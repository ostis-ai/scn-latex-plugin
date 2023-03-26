grammar SCnTex;

options
{
  language = Cpp;
}

@parser::header
{
#include "../translator/commands/commands.h"
}

scnTexText
  returns [std::string resultText]
  :
  {
  std::stringstream resultStream;
  }
  (result=scnTexCommand
    {
    resultStream << $result.resultText;
    }
  | lineComment WS
  )* EOF?
  {
  $resultText = resultStream.str();
  }
  ;

scnTexCommand
  returns [std::string resultText]
  locals [ScSCnTexCommand* command, std::string commandName]
  :
  (name=scnTexCommandName
  {
  $commandName = $name.text.substr(1);

  auto const & ignoreIt = ignoreCommandName.find($commandName);
  if (ignoreIt == ignoreCommandName.cend())
  {
      for(auto commandMap: command)
      {
          auto it = commandMap.first.find($commandName);
          if(it != commandMap.first.end())
          {
              $command = commandMap.second;
              break;
          }
          else
          {
             $command = nullptr;
          }
      }
      if($command == nullptr)
      {
        $command = latex;
      }
  }
  else
  {
    std::cout << "Ignore command: " << $commandName << std::endl;
    $command = nullptr;
  }
  })
  WS?
  {
  TexCommandParams params;
  params.push_back($commandName);
  }
  (
    WS? b=('{' | '[') WS?
    {
    std::stringstream argStream;
    }
    (
      WS? sent=scnTexCommandContent
      {
      if ($ctx->b->getText() == "{")
        argStream << $sent.text;
      }
      | WS? result=scnTexCommand
      {
      argStream << $result.resultText;
      }
    )*
    {
    if ($ctx->b->getText() == "{")
      params.push_back(argStream.str());
    }
    WS? ('}' | ']') WS?
  )*
  {
  if ($command != nullptr)
  {
    std::cout << "Interpreter command: " << $commandName << std::endl;
    $resultText = $command->Complete(params);
  }
  $command == nullptr;
  }
;

scnTexCommandContent
  : TEXT
  ;

scnTexCommandName
  : NAME
  ;

lineComment
    : '%' (NAME | TEXT | '{' | '}'| ']' | '[' )*
    ;

TEXT
  : ([а-яёЁА-Яa-zA-Z0-9]
  | '!' | '@' | '#' | '$' | '%' | '^' | '&' | '(' | ')'
  | '_' | '+' | '-' | '=' | '/' | '*' | '.' | '~' | '`'
  | ',' | '|' | ' ' | ':' | ';' | '<' | '>' | '?')+
  ;

NAME
  : '\\' ([a-zA-Z0-9\\])*
  ;

WS
  : [ \t\r\n\u2028\u2029]+
  ;
