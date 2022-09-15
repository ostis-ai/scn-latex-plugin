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
    && rm -rf /var/lib/apt/lists/*
RUN ln -sf /usr/local/texlive/*/bin/* /usr/local/bin/texlive

RUN tlmgr install microtype \
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
lh \
import \
ulem

COPY . /root/texmf/tex/latex/scn-latex-plugin
RUN texhash

RUN echo "#!/bin/bash" > /entrypoint.sh
RUN echo "cd \$(dirname \$1) && latexmk -pdf -bibtex \$(basename \$1)" >> /entrypoint.sh
RUN chmod +x /entrypoint.sh
WORKDIR /workdir

ENTRYPOINT [ "/entrypoint.sh" ]
CMD [ "tests.tex" ]
