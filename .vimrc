set nocompatible
filetype on
set number
set tabstop=4
set shiftwidth=4
set expandtab
set title
set backspace=indent,eol,start
set mouse=a
set completeopt-=preview


call plug#begin('~/.vim/plugged')

Plug 'neoclide/coc.nvim' "Like Intellisense 
Plug 'chiel92/vim-autoformat' "formater
Plug 'sheerun/vim-polyglot' "highlighter and indenter for all language

call plug#end()
syntax enable






"colorscheme solarized
"colorscheme monokai
"colorscheme gruvbox

set background=dark
set termguicolors
colorscheme monokai_pro
let g:lightline = {
      \ 'colorscheme': 'monokai_pro',
      \ }


"let g:molokai_original = 1
"colorscheme molokai


"colorscheme tender
"let g:lightline = { 'colorscheme': 'tender' }
"let g:airline_theme = 'tender'






nnoremap <F5> :!g++-12 -std=c++20 -O2 -Wall -Wextra -Wshadow -fsanitize=undefined -fno-sanitize-recover -DLOCAL -g % -o %:r && ./%:r<CR>
nnoremap<C-F5> :!clang++-14 -std=c++20 -Wall -Wextra -Wshadow -fsanitize=undefined -fno-sanitize-recover -DLOCAL  -g % -o %:r && ./%:r<CR>
inoremap<C-J> <Esc>
vnoremap<C-J> <Esc>
vnoremap<C-C> :w !xclip -i -sel c <CR>
noremap<C-P> :r !xclip -o -sel -c <CR>
noremap<C-A> ggVG
inoremap {<CR> {<CR>}<C-o>O




"----used in vim-jsx-pretty ----
let g:vim_jsx_pretty_highlight_close_tag = 1
let g:vim_jsx_pretty_colorful_config = 1 " default 0





"--- used in vim-c++ to remove curly brace error----
let c_no_curly_error=1



"--- file explorer ---
let g:netrw_banner = 0
let g:netrw_liststyle = 3
let g:netrw_browse_split = 4
let g:netrw_altv = 1
let g:netrw_winsize =20
let g:netrw_list_hide= '.*\.swp$,\~$,\.orig$'
"augroup ProjectDrawer
"  autocmd!
"  autocmd VimEnter * :Vexplore
"augroup END







"-----------------Auto-complete and template ------------
autocmd FileType html set omnifunc=htmlcomplete#CompleteTags
autocmd FileType css set omnifunc=csscomplete#CompleteCSS
autocmd FileType javascript set omnifunc=javascriptcomplete#CompleteJS
autocmd BufNewFile *.cpp execute "0r ~/.vim/template/".input("Template name: ").".cpp"





"----------------Auto-Format on Save -----------------
"------------C++-----------


let g:formatterpath = ['/usr/share/clang/clang-format-10/clang-format.py']
au BufWrite *.cpp :Autoformat


"---------Javascript------

let g:formatterpath = ['/usr/local/lib/node_modules/js-beautify/js/index.js']

au BufWrite *.js,*.html,*.css,*.jsx :Autoformat




"--- for removing background color in vim and using the terminal background ---

hi Normal ctermbg=none

" use <tab> to trigger completion and navigate to the next complete item
function! CheckBackspace() abort
  let col = col('.') - 1
  return !col || getline('.')[col - 1]  =~# '\s'
endfunction

inoremap <silent><expr> <Tab>
      \ coc#pum#visible() ? coc#pum#next(1) :
      \ CheckBackspace() ? "\<Tab>" :
      \ coc#refresh()
"select from first errorfix (put this line in CocConfig)-{"suggest.noselect" : true}





"END
