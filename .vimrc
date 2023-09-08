"set nocompatible
filetype on
set number
set title
"set backspace=indent,eol,start
set noexpandtab tabstop=2 shiftwidth=2
set softtabstop=2
set mouse=a
set completeopt-=preview


call plug#begin('~/.vim/plugged')

Plug 'neoclide/coc.nvim', {'branch': 'release'} "like intellisense
Plug 'chiel92/vim-autoformat' "formatter
Plug 'sheerun/vim-polyglot' "highlighter and indenter for all language
Plug 'maxmellon/vim-jsx-pretty' "highlighter for jsx files
Plug 'joshdick/onedark.vim'


call plug#end()
syntax enable

"-----------------------------------------------------------------------


"colorscheme solarized
"colorscheme monokai
"colorscheme gruvbox
"colorscheme onedark

"set background=dark
"set termguicolors
"colorscheme monokai_pro
"let g:lightline = {
"      \ 'colorscheme': 'monokai_pro',
"      \ }

"let g:molokai_original = 1
"colorscheme molokai

"colorscheme tender
"let g:lightline = { 'colorscheme': 'tender' }
"let g:airline_theme = 'tender'






"------------------------------------------------------------------------

nnoremap <F5> :!g++-12 -std=c++20 -O2 -Wall -Wextra -Wshadow -fsanitize=undefined -fno-sanitize-recover -DLOCAL -g % -o %:r && ./%:r<CR>
nnoremap<C-F5> :!clang++-14 -std=c++20 -Wall -Wextra -Wshadow -fsanitize=undefined -fno-sanitize-recover -DLOCAL  -g % -o %:r && ./%:r<CR>
inoremap<C-J> <Esc>
inoremap {<CR> {<CR>}<C-o>O
vnoremap<C-J> <Esc>
vnoremap<C-C> :w !xclip -i -sel c <CR>
noremap<C-P> :r !xclip -o -sel -c <CR>
noremap<C-A> ggVG
noremap<C-T> :tabnew <CR>
noremap<C-E> :Explore <CR>






"----used in vim-jsx-pretty ----
let g:vim_jsx_pretty_highlight_close_tag = 1
let g:vim_jsx_pretty_colorful_config = 1 " default 0





"------------- used in vim-c++ to remove curly brace error-------------------


let c_no_curly_error=1


"-----------------------------------------------------------------------------


" file explorer
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


"-------------------------------------------------------------------------------


"----------------Auto-Format on Save -----------------
"------------C++-----------


let g:formatterpath = ['/usr/share/clang/clang-format-14/clang-format.py']
au BufWrite *.cpp,*.c :Autoformat


"---------Javascript------

let g:formatterpath = ['/usr/local/lib/node_modules/js-beautify/js/index.js']

au BufWrite *.js,*.html,*.css,*.jsx :Autoformat


"--------------------------------- color change -----------------------------------
"gui ==  gvim
"cterm == terminal vim (only this in my case matter)
"terminal support 1-256 colors you can google all the colors/print on cmd itself 
"----------------------------------------------------------------------------------
"AlienBlood looking good on this settings


"for removing background color in vim and using the terminal background
hi Normal ctermbg=none
"suggestion box
highlight CocFloating ctermfg=white  ctermbg=black 
"side line warning and error when comes
highlight SignColumn ctermbg=none guibg=white ctermfg=white guifg=white
"change the color of background color of selected text in visual mode
highlight Visual ctermbg=236 guibg=lightgray
"Parenthesis background and foreground color when cursor hovers
highlight MatchParen ctermfg=214 ctermbg=none


"------------------------------------------------------------------------------



"use <tab> to trigger completion and navigate to the next complete item
function! CheckBackspace() abort
  let col = col('.') - 1
  return !col || getline('.')[col - 1]  =~# '\s'
endfunction

inoremap <silent><expr> <Tab>
      \ coc#pum#visible() ? coc#pum#next(1) :
      \ CheckBackspace() ? "\<Tab>" :
      \ coc#refresh()




"--------------------------------------------------------------------------------


"select from first errorfix-{"suggest.noselect" : true}



"--------------------------------------------------------------------------------


"fix tab name size
if exists( '+showtabline' )
    function! MyTabLine()
        let s = ''
        let wn = ''
        let t = tabpagenr()
        let i = 1
        let cnt = 0
        let totalLen = 0
        while i <= tabpagenr( '$' )
          let winnr = tabpagewinnr( i )
          let buflist = tabpagebuflist( i )
          let bufnr = buflist[winnr - 1]
          let file = bufname( bufnr )
          let buftype = getbufvar( bufnr , 'buftype' )
          if buftype == 'nofile'
              if file =~ '\/.'
                  let file = substitute( file , '.*\/\ze.' , '' , '' )
              endif
          else
              let file = fnamemodify( file , ':p:t' )
          endif
        "<Number><Space><file><Space>
          let totalLen = totalLen + 3 + len(file)
          let i = i + 1
        endwhile
        let i = 1 
        while i <= tabpagenr( '$' )
            let buflist = tabpagebuflist( i )
            let winnr = tabpagewinnr( i )
            let s .= '%' . i . 'T'
            let s .= ( i == t ? '%1*' : '%2*' )
            let wn = tabpagewinnr( i ,'$' )
            let s .= '%#TabNum#'
            let s .= i
            "let s .= '%*'
            let s .= ( i == t ? '%#TabLineSel#' : '%#TabLine#' )
            let bufnr = buflist[winnr - 1]
            let file = bufname( bufnr )
            let buftype = getbufvar( bufnr , 'buftype' )
            if buftype == 'nofile'
                if file =~ '\/.'
                    let file = substitute( file , '.*\/\ze.' , '' , '' )
                endif
            else
                let file = fnamemodify( file , ':p:t' )
            endif

            "echo totalLen . "/" . &columns . ", file=" . file
            if totalLen > &columns && len(file) > 16
                let file = strpart( file, 0, 6 )  . "~" . strpart( file, len(file)-10 )
            endif
            if file == ''
                let file = '[No Name]'
            endif
            let s .= ' ' . file . ' '
            let i = i + 1
        endwhile
        let s .= '%T%#TabLineFill#%='
        let s .= ( tabpagenr('$') > 1 ? '%999XX' : 'X' )
        return s
    endfunction
    set stal=2
    set tabline=%!MyTabLine()
    highlight link TabNum Special
endif


"END
