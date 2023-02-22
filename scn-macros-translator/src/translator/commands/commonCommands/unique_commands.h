#pragma once

#include "../command.h"

using namespace helper;

class TexUniqueCommand : public ScSCnTexCommand
{
public:
    std::string Complete(TexCommandParams const &params) override;
};

class ScnStartSubStructCommand : public ScSCnTexCommand
{
public:
    std::string Complete(TexCommandParams const &params) override
    {
        std::stringstream result;
        result << texSlash << "begin" << openBr << "scnsubstruct" << closeBr << newline;
        return result.str();
    };
};

class BeginCommand : public ScSCnTexCommand
{
public:
    std::string Complete(TexCommandParams const &params) override
    {
        std::stringstream result;
        result << texSlash << "begin" << openBr << GetFirstParameter(params) << closeBr << newline;
        return result.str();
    };
};

class EndCommand : public ScSCnTexCommand
{
public:
    std::string Complete(TexCommandParams const &params) override
    {
        std::stringstream result;
        result << texSlash << "end" << openBr << GetFirstParameter(params) << closeBr << newline;
        return result.str();
    };
};

class ScnStartSetCommand : public ScSCnTexCommand
{
public:
    std::string Complete(TexCommandParams const &params) override
    {
        std::stringstream result;
        result << texSlash << "begin" << openBr << "scnset" << closeBr << newline;
        return result.str();
    };
};

class ScnEndStructCommand : public ScSCnTexCommand
{
public:
    std::string Complete(TexCommandParams const &params) override
    {
        std::stringstream result;
        result << texSlash << "end" << openBr << "scnstruct" << closeBr << newline;
        return result.str();
    };
};

class ScnStructInclusionCommand : public ScSCnTexCommand
{
public:
    std::string Complete(TexCommandParams const &params) override
    {
        std::stringstream result;
        result << texSlash << "end" << openBr << "subset" << closeBr << openBr << GetFirstParameter(params) << closeBr
               << newline;
        return result.str();
    };
};

class ScnBigspaceCommand : public ScSCnTexCommand
{
public:
    std::string Complete(TexCommandParams const &params) override
    {
        std::stringstream result;
        result << texSlash << "bigspace" << newline;
        return result.str();
    };
};

class ScnFragmentCaptionCommand : public ScSCnTexCommand
{
public:
    std::string Complete(TexCommandParams const &params) override
    {
        std::stringstream result;
        result << texSlash << "scnsegmentheader" << openBr << GetFirstParameter(params) << closeBr << newline;
        return result.str();
    };
};

class ScnMakeSetLocalCommand : public ScSCnTexCommand
{
public:
    std::string Complete(TexCommandParams const &params) override
    {
        std::stringstream result;
        result << texSlash << "begin" << openBr << "scnset" << closeBr << newline << beginToDo << newline
               << GetFirstParameter(params) << newline << endToDo << newline << texSlash << "end" << openBr << "scnset"
               << closeBr << newline;
        return result.str();
    };
};

class ScnMakeVectorLocalCommand : public ScSCnTexCommand
{
public:
    std::string Complete(TexCommandParams const &params) override
    {
        std::stringstream result;
        result << texSlash << "begin" << openBr << "scnvector" << closeBr << newline << beginToDo << newline
               << GetFirstParameter(params) << newline << endToDo << newline << texSlash << "end" << openBr
               << "scnvector" << closeBr << newline;
        return result.str();
    };
};

class ScnMakeSetCommand : public ScSCnTexCommand
{
public:
    std::string Complete(TexCommandParams const &params) override
    {
        std::stringstream result;
        result << texSlash << "begin" << openBr << "scnset" << closeBr << newline << ParseByDelim(params) << texSlash
               << "end" << openBr << "scnset" << closeBr << newline;
        return result.str();
    };
};

class ScnIdtfDefCommand : public ScSCnTexCommand
{
public:
    std::string Complete(TexCommandParams const &params) override
    {
        std::stringstream result;
        result << texSlash << "scnidtftext" << openBr << "definition" << closeBr << openBr << GetFirstParameter(params)
               << closeBr << newline;
        return result.str();
    };
};

class ScnIdtfExpCommand : public ScSCnTexCommand
{
public:
    std::string Complete(TexCommandParams const &params) override
    {
        std::stringstream result;
        result << texSlash << "scnidtftext" << openBr << "explanation" << closeBr << openBr << GetFirstParameter(params)
               << closeBr << newline;
        return result.str();
    };
};

class ScnInLineSourceCommentParCommand : public ScSCnTexCommand
{
public:
    std::string Complete(TexCommandParams const &params) override
    {
        std::stringstream result;
        result << texSlash << "scnsourcecommentinline" << openBr << GetFirstParameter(params) << closeBr << newline;
        return result.str();
    };
};

class ScnCiteCommand : public ScSCnTexCommand
{
public:
    std::string Complete(TexCommandParams const &params) override
    {
        std::stringstream result;
        result << texSlash << "cite" << openBr << GetFirstParameter(params) << closeBr;
        return result.str();
    };
};

class IncludeGraphicsCommand : public ScSCnTexCommand
{
public:
    std::string Complete(TexCommandParams const &params) override
    {
        std::stringstream result;
        result << "[20em]" << openBr << GetLastParameter(params) << closeBr;
        return result.str();
    };
};

class ScnFileImageCommand : public ScSCnTexCommand
{
public:
    std::string Complete(TexCommandParams const &params) override
    {
        std::stringstream result;
        result << texSlash << "scnfileimage" << openBr << GetFirstParameter(params) << closeBr << newline;
        return result.str();
    };
};

class ScnFileScgCommand : public ScSCnTexCommand
{
public:
    std::string Complete(TexCommandParams const &params) override
    {
        std::stringstream result;
        result << texSlash << "scnfileimage[20em]" << openBr << GetFirstParameter(params) << closeBr << newline;
        return result.str();
    };
};

class ScnEqScgCommand : public ScSCnTexCommand
{
public:
    std::string Complete(TexCommandParams const &params) override
    {
        std::stringstream result;
        result << texSlash << "scneq" << openBr << texSlash << "scnfileimage[20em]" << openBr
               << GetFirstParameter(params) << closeBr << closeBr << newline;
        return result.str();
    };
};

class ScnHasElementsCommand : public ScSCnTexCommand
{
public:
    std::string Complete(TexCommandParams const &params) override
    {
        std::stringstream result;
        result << texSlash << "begin" << openBr << "scnhaselementrolelist" << closeBr << newline << ParseByDelim(params)
               << texSlash << "end" << openBr << "scnhaselementrolelist" << closeBr << newline;
        return result.str();
    };
};

class ScnSdRelationCommand : public ScSCnTexCommand
{
public:
    std::string Complete(TexCommandParams const &params) override
    {
        std::stringstream result;
        result << texSlash << "begin" << openBr << "scnhaselementrolelist" << closeBr << openBr
               << "исследуемое отношение" << closeBr << newline << beginToDo << newline << GetFirstParameter(params)
               << newline << endToDo << newline << texSlash << "end" << openBr << "scnhaselementrolelist" << closeBr
               << newline;
        return result.str();
    };
};

class ScnSdClassCommand : public ScSCnTexCommand
{
public:
    std::string Complete(TexCommandParams const &params) override
    {
        std::stringstream result;
        result << texSlash << "begin" << openBr << "scnhaselementrolelist" << closeBr << openBr
               << "класс объектов исследования" << closeBr << newline << beginToDo << newline
               << GetFirstParameter(params) << newline << endToDo << newline << closeBr << texSlash << "end" << openBr
               << "scnhaselementrolelist" << closeBr << newline;
        return result.str();
    };
};

class ScnSdmainClassSingleCommand : public ScSCnTexCommand
{
public:
    std::string Complete(TexCommandParams const &params) override
    {
        std::stringstream result;
        result << texSlash << "begin" << openBr << "scnhaselementrole" << closeBr << openBr
               << "класс объектов исследования" << closeBr << newline << GetFirstParameter(params) << texSlash << "end"
               << openBr << "scnhaselementrole" << closeBr << newline;
        return result.str();
    };
};