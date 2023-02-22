#include <map>
#include "unique_commands.h"

static std::map<std::string, ScSCnTexCommand *> const commands =
        {
                {"scnstartsubstruct",         new ScnStartSubStructCommand()},
                {"begin",                     new BeginCommand()},
                {"end",                       new EndCommand()},
                {"scnstartset",               new ScnStartSetCommand()},
                {"scnstartsetlocal",          new ScnStartSetCommand()},
                {"scnendstruct",              new ScnEndStructCommand()},
                {"scnstructinclusion",        new ScnStructInclusionCommand()},
                {"scnbigspace",               new ScnBigspaceCommand()},
                {"scnfragmentcaption",        new ScnFragmentCaptionCommand()},
                {"scnmakesetlocal",           new ScnMakeSetLocalCommand()},
                {"scnmakevectorlocal",        new ScnMakeVectorLocalCommand()},
                {"scnmakeset",                new ScnMakeSetCommand()},
                {"scnidtfdef",                new ScnIdtfDefCommand()},
                {"scnidtfexp",                new ScnIdtfExpCommand()},
                {"scninlinesourcecommentpar", new ScnInLineSourceCommentParCommand()},
                {"scnauthorcomment",          new ScnInLineSourceCommentParCommand()},
                {"scncite",                   new ScnCiteCommand()},
                {"includegraphics",           new IncludeGraphicsCommand()},
                {"scnfileimage",              new ScnFileImageCommand()},
                {"scnfilescg",                new ScnFileScgCommand()},
                {"scgfileitem",               new ScnFileScgCommand()},
                {"scneqscg",                  new ScnEqScgCommand()},
                {"scnhaselements",            new ScnHasElementsCommand()},
                {"scnhaselementlist",         new ScnHasElementsCommand()},
                {"scnsdrelation",             new ScnSdRelationCommand()},
                {"scnsdclass",                new ScnSdClassCommand()},
                {"scnsdmainclass",            new ScnSdClassCommand()},
                {"scnsdmainclasssingle",      new ScnSdmainClassSingleCommand()}
        };

std::string TexUniqueCommand::Complete(
        TexCommandParams const &params)
{
    const std::string &commandName = GetCommandName(params);
    std::string result;
    auto const &it = commands.find(commandName);
    if (it != commands.cend())
    {
        result = it->second->Complete(params);
    }
    return result;
}
