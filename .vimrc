filetype plugin indent on
syntax on
set clipboard=unnamed
set shell=/bin/bash\ --rcfile\ ~/.bash_profile
set number numberwidth=3
inoremap <c-d> <esc>ddi
inoremap jk <esc>
" added these commands to learn NOT to use arrow keys while navigating
inoremap <esc> <nop>
inoremap <Up> <nop>
inoremap <Down> <nop>
inoremap <Left> <nop>
inoremap <Right> <nop>
inoremap { {}<esc>li
nnoremap ff yyp
let $BASH_ENV = "~/.bash_profile"
:iabbrev includes #include <iostream><cr>#include <cstdio><cr><cr>using namespace std;
