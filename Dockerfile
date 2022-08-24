FROM debian:11.4-slim AS installer
ENV PATH /usr/local/bin/texlive:$PATH
WORKDIR /install-tl-unx
RUN apt-get update
RUN apt-get install -y \
  perl \
  wget \
  xz-utils \
  fontconfig


RUN echo "selected_scheme scheme-basic\ntlpdbopt_install_docfiles 0\ntlpdbopt_install_srcfiles 0" > ./texlive.profile


RUN wget -nv https://mirror.ctan.org/systems/texlive/tlnet/install-tl-unx.tar.gz
RUN tar -xzf ./install-tl-unx.tar.gz --strip-components=1
RUN ./install-tl --profile=texlive.profile
RUN ln -sf /usr/local/texlive/*/bin/* /usr/local/bin/texlive
RUN tlmgr install \
  collection-fontsrecommended \
  latexmk

FROM debian:11.4-slim
ENV PATH /usr/local/bin/texlive:$PATH
WORKDIR /workdir
COPY --from=installer /usr/local/texlive /usr/local/texlive
RUN apt-get update \
  && apt-get install -y \
    perl \
    wget \
    git \
    python2 python-is-python2 \
    && rm -rf /var/lib/apt/lists/*
RUN ln -sf /usr/local/texlive/*/bin/* /usr/local/bin/texlive

RUN tlmgr install texliveonfly \
microtype \
etoolbox \
changepage \
ragged2e \
xcolor \
mathtools \
enumitem \
tocloft \
silence \
background \
xkeyval \
pgf \
everypage \
csquotes \
biblatex \
biber \
cyrillic \
babel-russian \
lh

COPY . /root/texmf/tex/latex/scn-latex-plugin
RUN texhash

ENTRYPOINT ["/bin/bash", "-c", "latexmk -pdf -bibtex tests.tex"]
