filetype plugin indent on
syntax on
set clipboard=unnamed
let $BASH_ENV = "~/.bash_profile"
set shell=/bin/bash\ --rcfile\ ~/.bash_profile
let mapleader = ","
let g:mapleader = ","
nnoremap <leader>w :w<CR>
set number numberwidth=3
" easier to map it to jk  
inoremap <c-d> <esc>ddi
inoremap jk <esc>
" added these commands to learn NOT to use arrow keys while navigating
inoremap <esc> <nop>
inoremap <Up> <nop>
inoremap <Down> <nop>
inoremap <Left> <nop>
inoremap <Right> <nop>
:iabbrev cppincludes #include <iostream><cr>#include <cstdio><cr>#include <vector><cr>#include <sstream><cr>#include <map><cr>#include <cmath><cr>#include <algorithm><cr><cr>using namespace std;
nnoremap <Up> <nop>
nnoremap <Down> <nop>
nnoremap <Left> <nop>
nnoremap <Right> <nop>
nnoremap <TAB> gt
set wildmode=longest:full
set wildmenu
" From SO,
" http://stackoverflow.com/questions/1878974/vim-how-to-redefine-tab-as-4-spaces/1878987#1878987
set smarttab
set expandtab
set tabstop=2
" size of an indent
set shiftwidth=2

 " a combination of spaces and tabs are used to simulate tab stops at a width
 " other than the (hard)tabstop
set softtabstop=2
set cindent
set hlsearch
inoremap {      {}<Left>
inoremap {<CR>  {<CR>}<Esc>O
inoremap {{     { 
inoremap {}     {}
execute pathogen#infect()
call pathogen#helptags() " generate helptags for everything in ‘runtimepath’
