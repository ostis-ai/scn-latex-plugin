## SCn-LaTeX plugin

This repository contains LaTeX plugin to write SCn code.

### Usage

To start using this plugin clone current repo in the directory with your project

```sh
mkdir -p ~/texmf/tex/latex
git clone https://github.com/ostis-ai/scn-latex-plugin ~/texmf/tex/latex
texhash
```

You can also use it with Docker.

```sh
docker build . -t scn-latex-plugin
docker run -v </abspath/to/project/folder>:/workdir -it --rm scn-latex-plugin <main .tex-file name>
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
