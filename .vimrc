set tabstop=4
set shiftwidth=4

set number
set ruler
set confirm

set path=**
set wildmenu
"set wildmode=list:longest,full 

set ignorecase
set smartcase

set hidden
set cindent
set noesckeys

syntax enable
set background=dark
colo solarized8_high

autocmd BufWritePre *.c %s/\s\+$//e
"autocmd BufNewFile *.c Stdheader

call plug#begin('~/.vim/plugged')

Plug 'elmcast/elm-vim'
Plug 'dense-analysis/ale'
Plug 'https://github.com/lifepillar/vim-solarized8.git'
Plug 'preservim/nerdcommenter'

call plug#end()

"MAPPINGS
nnoremap Y y$
nnoremap <SPACE> <C-d>
nnoremap <leader>nc o/*<ESC>o<ESC>Dd0i**<space><ESC>o*/<ESC>o<ESC>kkA
"command J bp
"command K bn
nnoremap  <silent>   <tab>  :if &modifiable && !&readonly && &modified <CR> :write<CR> :endif<CR>:bnext<CR>
nnoremap  <silent> <s-tab>  :if &modifiable && !&readonly && &modified <CR> :write<CR> :endif<CR>:bprevious<CR>


highlight ALEErrorsign ctermbg=DarkMagenta 
highlight ALEWarningsign ctermbg=DarkMagenta 



