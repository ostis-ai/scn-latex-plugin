## SCn-LaTeX plugin

This repository contains LaTeX plugin to write SCn code.

### Usage

To start using this plugin clone current repo in the directory with your project

```sh
git clone https://github.com/ostis-ai/scn-latex-plugin
```

You can also use it with Docker.

```sh
docker run -v </abspath/to/project/folder>:/workdir -it --rm ostis/ostis-standard <main .tex-file name>
```

### Example

```tex
\documentclass[graybox,envcountchap,sectrefs]{scn-latex-plugin/svmono}

\usepackage{scn-latex-plugin/scn}

\begin{document}
\end{document}
```
