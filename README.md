## SCn-LaTeX plugin

This repository contains LaTeX plugin to write SCn code.

### Installation

There are three possible ways to use this plugin:

* Global installation

```sh
mkdir -p ~/texmf/tex/latex
git clone https://github.com/ostis-ai/scn-latex-plugin ~/texmf/tex/latex
texhash
```

* Local installation for specific project (e.g. as git submodule)

```sh
# clone current repo where you'd like
git clone https://github.com/ostis-ai/scn-latex-plugin ./scn
# to compile main.tex you may use
TEXINPUTS=./scn: latexmk -pdf -bibtex ./main.tex
```

* You can also use it with Docker.

```sh
docker run -v </abspath/to/project/folder>:/workdir ostis/scn-latex-plugin:latest </path/to/main/tex/file>
```

### Example

```tex
\documentclass{scndocument}

\usepackage{scn}

\begin{document}
\begin{SCn}
\end{SCn}
\end{document}
```
