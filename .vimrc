filetype plugin indent on
syntax on
set clipboard=unnamed
let $BASH_ENV = "~/.bash_profile"
set shell=/bin/bash\ --rcfile\ ~/.bash_profile
let mapleader = ","
let g:mapleader = ","
nnoremap <leader>w :w,
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
colorscheme desert
set background=dark

:iabbrev includes #include <iostream><cr>#include <cstdio><cr><cr>using namespace std;
