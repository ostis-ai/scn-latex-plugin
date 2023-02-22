#pragma once

#include <map>
#include <set>

#include "command_defines.h"

using ScSCnTexCommands = std::map<std::set<std::string>, ScSCnTexCommand *>;

static std::set<std::string> const oneSameCommandName =
        {
                "scnheader",
                "scnstructheader",
                "scnheaderlocal",
                "scnstructheaderlocal",
                "scnstructidtf",
                "scnkeyword",
                "scnsectionheader",
                "scnsegmentheader",
                "scnfileitem",
                "scneqfile",
                "scneqimage",
                "scneqtable",
                "scneqfileclass",
                "scnsubset",
                "scnnotsubset",
                "scnsuperset",
                "scniselement",
                "scnisvarelement",
                "scnhaselement",
                "scnhasvarelement",
                "scnidtf",
                "scnfileclass",
                "scnfilelong",
                "scnfiletable",
                "scnsourcecomment",
                "scneq"
        };

static std::set<std::string> const twoSameCommandName =
        {
                "scnrelfrom",
                "scnrelsuperset",
                "scnvarrelfrom",
                "scnrelto",
                "scnvarrelto",
                "scnrelboth",
                "scnhaselementrole",
                "scnhasvarelementrole",
                "scniselementrole",
                "scnidtftext",
                "scntext"
        };

static std::set<std::string> const zeroSameCommandName =
        {
                "scnendcurrentsectioncomment",
                "scnendsegmentcomment",
                "scnendfragmentcomment",
                "currentname",
                "scnsupergroupsign"
        };

static std::set<std::string> const ignoreCommandName =
        {
                "scnaddlevel",
                "scnaddhind",
                "scnresetlevel"
        };

static std::set<std::string> const oneToEnvironmentCommandName =
        {
                "scneqtoset",
                "scneqtovector",
                "scnhassubstruct",
                "scnhaselementset",
                "scnhaselementvector",
                "scnset",
                "scnvector",
                "scnsubdividing"
        };

static std::set<std::string> const twoToEnvironmentCommandName =
        {
                "scnrelfromlist",
                "scnreltolist",
                "scnrelbothlist",
                "scnrelfromset",
                "scnrelfromvector",
                "scnreltoset",
                "scnreltovector",
        };

static std::set<std::string> const oneToTextCommandName =
        {
                "scnexplanation",
                "scnnote",
                "scndefinition",
                "scnevolution",
                "scnproblems",
                "scnevolutiondirections",
                "scnevolutionproblems",
                "scnsolutionapproach",
                "scnadvantages",
                "scnprinciples",
                "scnspheresapplication",
                "scnseminclusion",
                "scneditor",
                "scneditors",
                "scnmonographychapter"
        };

static std::set<std::string> const uniqueCommands =
        {
                "scnstartsubstruct",
                "scnstartset",
                "scnstartsetlocal",
                "scnendstruct",
                "scnstructinclusion",
                "scnbigspace",
                "scnfragmentcaption",
                "scgfileitem",
                "scneqscg",
                "scnmakesetlocal",
                "scnmakevectorlocal",
                "scnmakeset",
                "scnidtfdef",
                "scnidtfexp",
                "scnfilescg",
                "scninlinesourcecommentpar",
                "scnauthorcomment",
                "scnsdmainclass",
                "scnsdmainclasssingle",
                "scnsdclass",
                "scnsdrelation",
                "scnhaselementlist",
                "scnhaselements",
                "scnfileimage",
                "includegraphics",
                "scncite",
                "begin",
                "end"
        };

static ScSCnTexCommands const command = {
        {oneSameCommandName,          new TexOneSameCommand()},
        {twoSameCommandName,          new TexTwoSameCommand()},
        {zeroSameCommandName,         new TexZeroSameCommand()},
        {oneToEnvironmentCommandName, new TexOneToEnvironmentCommand()},
        {twoToEnvironmentCommandName, new TexTwoToEnvironmentCommand()},
        {oneToTextCommandName,        new TexOneToTextCommand()},
        {uniqueCommands,              new TexUniqueCommand()}

};

static ScSCnTexCommand *latex = new TexCommand();
