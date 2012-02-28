if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
imap <silent> <Plug>IMAP_JumpBack =IMAP_Jumpfunc('b', 0)
imap <silent> <Plug>IMAP_JumpForward =IMAP_Jumpfunc('', 0)
inoremap <silent> <expr> <Plug>AcpOnPopupPost acp#onPopupPost()
imap <silent> <F7> :exe ":ptag ".expand("<cword>")
imap <silent> <F6> :call GenTags()
imap <silent> <F4> :nohl
imap <silent> <F3> :silent make
imap <silent> <F2> :silent write
map! <S-Insert> <MiddleMouse>
nnoremap  :cprev 
smap 	 i<BS>	
vmap <NL> <Plug>IMAP_JumpForward
nmap <NL> <Plug>IMAP_JumpForward
nnoremap  :cnext 
nnoremap <silent> w :CCTreeWindowToggle
nmap i :cs find i ^=expand("<cfile>")$
nmap f :cs find f =expand("<cfile>")
nmap e :cs find e =expand("<cword>")
nmap t :cs find t =expand("<cword>")
nmap c :cs find c =expand("<cword>")
nmap d :cs find d =expand("<cword>")
nmap g :cs find g =expand("<cword>")
nmap s :cs find s =expand("<cword>")  
noremap   <PageDown>
map ,e :e =expand("%:h")/
nmap K <Plug>ManPageView
vnoremap Q gq
nnoremap Q gqap
vmap [% [%m'gv``
map <silent> \w\t <Plug>VimwikiTabMakeDiaryNote
map <silent> \w\w <Plug>VimwikiMakeDiaryNote
map <silent> \ws <Plug>VimwikiUISelect
map <silent> \wt <Plug>VimwikiTabGoHome
map <silent> \ww <Plug>VimwikiGoHome
nmap <silent> \cv <Plug>VCSVimDiff
nmap <silent> \cu <Plug>VCSUpdate
nmap <silent> \cU <Plug>VCSUnlock
nmap <silent> \cs <Plug>VCSStatus
nmap <silent> \cr <Plug>VCSReview
nmap <silent> \cq <Plug>VCSRevert
nmap <silent> \cn <Plug>VCSAnnotate
nmap <silent> \cN <Plug>VCSSplitAnnotate
nmap <silent> \cl <Plug>VCSLog
nmap <silent> \cL <Plug>VCSLock
nmap <silent> \ci <Plug>VCSInfo
nmap <silent> \cg <Plug>VCSGotoOriginal
nmap <silent> \cG <Plug>VCSClearAndGotoOriginal
nmap <silent> \cd <Plug>VCSDiff
nmap <silent> \cD <Plug>VCSDelete
nmap <silent> \cc <Plug>VCSCommit
nmap <silent> \ca <Plug>VCSAdd
map \mbt <Plug>TMiniBufExplorer
map \mbu <Plug>UMiniBufExplorer
map \mbc <Plug>CMiniBufExplorer
map \mbe <Plug>MiniBufExplorer
nmap \caL <Plug>CalendarH
nmap \cal <Plug>CalendarV
map \o :call CopyCat() 
map \ft :cscope find t 
map \fs :cscope find s 
map \fi :cscope find i 
map \fg :cscope find g 
map \ff :cscope find f 
map \fe :cscope find e 
map \fd :cscope find d 
map \fc :cscope find c 
vmap ]% ]%m'gv``
vmap a% [%v]%
nmap gx <Plug>NetrwBrowseX
map g :cs find s =expand("<cword>")
map g :cs find c =expand("<cword>")
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#NetrwBrowseX(expand("<cWORD>"),0)
nnoremap <silent> <Plug>VCSVimDiff :VCSVimDiff
nnoremap <silent> <Plug>VCSUpdate :VCSUpdate
nnoremap <silent> <Plug>VCSUnlock :VCSUnlock
nnoremap <silent> <Plug>VCSStatus :VCSStatus
nnoremap <silent> <Plug>VCSSplitAnnotate :VCSAnnotate!
nnoremap <silent> <Plug>VCSReview :VCSReview
nnoremap <silent> <Plug>VCSRevert :VCSRevert
nnoremap <silent> <Plug>VCSLog :VCSLog
nnoremap <silent> <Plug>VCSLock :VCSLock
nnoremap <silent> <Plug>VCSInfo :VCSInfo
nnoremap <silent> <Plug>VCSClearAndGotoOriginal :VCSGotoOriginal!
nnoremap <silent> <Plug>VCSGotoOriginal :VCSGotoOriginal
nnoremap <silent> <Plug>VCSDiff :VCSDiff
nnoremap <silent> <Plug>VCSDelete :VCSDelete
nnoremap <silent> <Plug>VCSCommit :VCSCommit
nnoremap <silent> <Plug>VCSAnnotate :VCSAnnotate
nnoremap <silent> <Plug>VCSAdd :VCSAdd
vmap <silent> <Plug>IMAP_JumpBack `<i=IMAP_Jumpfunc('b', 0)
vmap <silent> <Plug>IMAP_JumpForward i=IMAP_Jumpfunc('', 0)
vmap <silent> <Plug>IMAP_DeleteAndJumpBack "_<Del>i=IMAP_Jumpfunc('b', 0)
vmap <silent> <Plug>IMAP_DeleteAndJumpForward "_<Del>i=IMAP_Jumpfunc('', 0)
nmap <silent> <Plug>IMAP_JumpBack i=IMAP_Jumpfunc('b', 0)
nmap <silent> <Plug>IMAP_JumpForward i=IMAP_Jumpfunc('', 0)
nnoremap <silent> <Plug>CalendarH :cal Calendar(1)
nnoremap <silent> <Plug>CalendarV :cal Calendar(0)
nmap <silent> <F7> :exe ":ptag ".expand("<cword>")
nmap <silent> <F6> :call GenTags()
map <silent> <F4> :nohl
map <silent> <F3> :silent make :copen
map <silent> <F2> :silent write
noremap <BS> <PageUp>
noremap <Right> :MBEbn
noremap <Down> :Tlist 
noremap <Left> :MBEbp 
noremap <Up> :Ex 
nmap <C-Space><C-Space>d:vert scs find d =expand("<cword>")
nmap <C-Space><C-Space>i:vert scs find i ^=expand("<cfile>")$
nmap <C-Space><C-Space>e:vert scs find e =expand("<cword>")
nmap <C-Space><C-Space>t:vert scs find t =expand("<cword>")
nmap <C-Space><C-Space>c:vert scs find c =expand("<cword>")
nmap <C-Space><C-Space>g:vert scs find g =expand("<cword>")
nmap <C-Space><C-Space>s:vert scs find s =expand("<cword>")
nmap <C-Space>i :scs find i ^=expand("<cfile>")$
nmap <C-Space>f :scs find f =expand("<cfile>")
nmap <C-Space>e :scs find e =expand("<cword>")
nmap <C-Space>t :scs find t =expand("<cword>")
nmap <C-Space>c :scs find c =expand("<cword>")
nmap <C-Space>d :scs find d =expand("<cword>")
nmap <C-Space>g :scs find g =expand("<cword>")
nmap <C-Space>s :scs find s =expand("<cword>")
map <S-Insert> <MiddleMouse>
imap 	 <Plug>Jumper
imap <NL> <Plug>IMAP_JumpForward
imap jj 
iabbr xuser =g:username 
iabbr ydate =strftime("%B %d, %Y") 
iabbr xdate =strftime("%d/%m/%y %H:%M:%S") 
let &cpo=s:cpo_save
unlet s:cpo_save
set background=dark
set backspace=indent,eol,start
set browsedir=current
set cindent
set clipboard=autoselect,exclude:cons\\|linux,unnamed
set cmdheight=2
set complete=.,w,b,u,t,i,k
set confirm
set cscopequickfix=s-,c-,d-,i-,t-,e-
set cscopetag
set cscopeverbose
set noequalalways
set expandtab
set fileencodings=ucs-bom,utf-8,default,latin1
set formatoptions=crqn
set guicursor=a:blinkon0
set guifont=Inconsolata\ Medium\ 12
set guioptions=
set helplang=en
set hidden
set history=1000
set hlsearch
set ignorecase
set incsearch
set iskeyword=a-z,A-Z,_,48-57,_,-,>
set laststatus=2
set mouse=a
set pastetoggle=<F5>
set ruler
set runtimepath=~/.vim,/usr/share/vim,/usr/share/vim/vim73/
set scrolloff=10
set shiftwidth=2
set shortmess=atI
set showcmd
set showmatch
set smartcase
set statusline=%F%m%r%h%w\ [%Y]\ [%04l,%04v][%p%%]\ [LEN=%L]\ %{VimBuddy()}
set suffixes=.bak,~,.swp,.o,.info,.aux,.log,.dvi,.bbl,.blg,.brf,.cb,.ind,.idx,.ilg,.inx,.out,.toc
set tabstop=2
set termencoding=utf-8
set textwidth=72
set viminfo='100,<50,s10,h,!,n~/.vim/viminfo
set visualbell
set whichwrap=b,s,<,>,h,l
set wildignore=*.bak,*.o,*.e,*~
set wildmenu
set wildmode=longest:full,full
set window=44
" vim: set ft=vim :
