# SCn-macros-translator

SCn-macros-translator is a tool for translating SCn-represented *.tex files into new macros *.tex files.

## How to use

- download standard project and compile *.pdf file and save it
- checkout to new-macros branch
- compile *.pdf file
- uncomment include of needed file to translate
- if your file include some of those commands (this commands very rare): `scnstartstruct, scnendstructlocal, scnstartfile, scnendfile, scneqhierstruct, scnendhierstruct, scnfragmentheader, scnfragmentcaptiontext, scnfileshort, scnfilescn, scncomment, scnsourcecommentpar, scniselementlist` change to another old macros commands;
- please check syntax of this command `item{...}`
- if there are `{` and `}` in ordinary text, please remove it and then added to final file
- to build macros translator run 
    ```
    cd scripts 
    ./make_all.sh
    cd ..
    ```
- to run translator run 
    ``` 
    ./bin/macros-translator -s <path to folder with scn-tex sources> -t <target folder for translated scs sources>
    ```
- if there are `TODO: check by human{}` please check formatting
- please check that `begin{}` and `end{}` has same naming
