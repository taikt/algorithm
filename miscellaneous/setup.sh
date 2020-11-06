#!/bin/sh
sudo apt-get install curl
mkdir -p ~/.vim/autoload ~/.vim/bundle
curl -LSso ~/.vim/autoload/pathogen.vim https://tpo.pe/pathogen.vim
cd ~/.vim/bundle
git clone https://github.com/scrooloose/nerdtree.git
git clone git://github.com/majutsushi/tagbar
git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim
cd ~/.vim
git clone https://github.com/flazz/vim-colorschemes.git
cp -rf vim-colorschemes/colors .
#ln -s .vimrc ~/.vimrc
