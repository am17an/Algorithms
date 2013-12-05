filetype off
call pathogen#incubate()
filetype plugin indent on
syntax on
" color
let g:molokai_original = 1
set background=dark
set clipboard=unnamed
let $BASH_ENV = "~/.bash_profile"
set shell=/bin/bash\ --rcfile\ ~/.bash_profile
set relativenumber
set undofile
set backspace=indent,eol,start
let mapleader = ","
set listchars=tab:▸\ ,eol:¬,extends:❯,precedes:❮
set number numberwidth=3 " For setting the line number width
" easier to map it to jk
" basic mappings
nnoremap / /\v
vnoremap / /\v
set ignorecase
set smartcase
set hlsearch
set incsearch
set showmatch

set hlsearch
au VimEnter * echom "Hello Aman Gupta!"
onoremap in( :<c-u>normal! f(vi(<cr>
nnoremap <leader>" viw<esc>a"<esc>hbi"<esc>lel
nnoremap <leader>cc :so ~/.vimrc<cr> 
nnoremap <leader>vim :vs ~/.vimrc<CR>
nnoremap <leader>o :edit 
nnoremap <leader><space> :noh<cr>
nnoremap cwd :cd %:p:h<cr>
nnoremap lcwd :lcd %:p:h<cr>
set nu
set nocompatible
inoremap jk <esc>
set cindent
" folding setting
set foldmethod=indent
set foldnestmax=10
set nofoldenable
set foldlevel=1

" Vertical Windows
nnoremap <leader>w <C-w>v<C-w>l
nnoremap <C-l> <C-w>l
nnoremap <C-h> <C-w>h
nnoremap <C-j> <C-w>j
nnoremap <C-k> <C-w>k
" Training commmands
inoremap <esc> <nop>
inoremap <Up> <nop>
inoremap <Down> <nop>
inoremap <Left> <nop>
inoremap <Right> <nop>
nnoremap <Up> <nop>
nnoremap <Down> <nop>
nnoremap <Left> <nop>
nnoremap <Right> <nop>
nnoremap Ajk <nop>
" Wildmode
set wildmode=longest:full
set wildmenu
" Tabs 
set smarttab
set expandtab
set tabstop=2
set shiftwidth=2
set softtabstop=2
" Shortcuts
" For autocompletion, hackish
inoremap {<CR>  {<CR>}<Esc>O
inoremap {{     { 
inoremap {}     {}
" Abbrev, must be a better way to do this
:iabbrev cppincludes #include <iostream><cr>#include <cstdio><cr>#include <vector><cr>#include <sstream><cr>#include <map><cr>#include <cmath><cr>#include <algorithm><cr><cr>using namespace std;
set pastetoggle=<C-P><C-P>
nnoremap L $
nnoremap H ^
" Plugins
execute pathogen#infect()
call pathogen#helptags() " generate helptags for everything in ‘runtimepath’
nnoremap NN :NERDTreeToggle<CR>
set runtimepath^=~/.vim/bundle/ctrlp.vim
set laststatus =2
