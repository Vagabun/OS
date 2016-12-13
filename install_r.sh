#!/bin/bash

if [[ $# -eq 0 ]]
then
  echo -e "please specify version of R language\nexample: ./install_r 3.0.0"
  echo "place this script into your home folder and mkdir distrib" 
  exit
fi

path=$(pwd)
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
installPath=$path"/R_lang/"$name
mkdir $installPath
cd $name
echo "configuring "$name
#on some machines we can get configure error with F77 compiler, readline, zlib, bzip2, liblzma, pcre, libcurl
./configure --prefix=$installPath --with-x=no --with-readline=no >/dev/null
echo "make"
make >/dev/null
echo "make install"
make install >/dev/null
cd ../../
echo "create symbolic link"
ln -s "R_lang/"$name"/bin/R" $name
echo "working with PATH variable"
export PATH=$installPath"/bin":$PATH

