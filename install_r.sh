#!/bin/bash

if [[ $# -eq 0 ]]
then
  echo -e "please specify version of R language\nexample: ./install_r 3.0.0"
  exit
fi

ver=$1
name="R-"$ver
distr_name=$name".tar.gz"
link="https://cran.r-project.org/src/base/R-3/"$name".tar.gz"

lsout=$(ls $name 2>/dev/null)
if ! [ -z $lsout ]
then
  echo "you have already installed R"
  exit
fi

cd distrib

lsout=$(ls $distr_name 2>/dev/null)
if [ -z $lsout ] 
then
  echo "start downloading..."
  wget $link 
  if [[ $? -ne 0 ]]
  then
    echo "you have specified wrong version of R, please try again"
    ls
    exit
  fi 
else
  echo "file exists in distrib folder"
fi

echo "start installing "$name
tar -xzf $distr_name
