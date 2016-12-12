#!/bin/bash

if [[ $# -eq 0 ]]
then echo -e "please specify version of R language\nexample: ./install_r 3.0.0"
fi

ver=$1
name="R-"$ver
link="https://cran.r-project.org/src/base/R-3/"$name".tar.gz"

distr=$(ls $name 2>/dev/null)
if ! [ -z $distr ]
then
  echo "you have already installed R"
  exit
fi
