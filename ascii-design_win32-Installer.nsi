;--------------------------------
;Include Modern UI

  !include "MUI.nsh"

;--------------------------------
;Configuration

  ;General
  Name "FaStEr"
  Caption "Installazione di ascii-design 0.1"
  OutFile "ascii-design_0.1-win32-installer.exe"

  ;Default installation folder
  InstallDir "$PROGRAMFILES\Faster\ascii-design"
  
  ;Get installation folder from registry if available
  ;InstallDirRegKey HKCU "Software\Faster\ascii-design" ""


;--------------------------------
;Interface Configuration
  !define MUI_ABORTWARNING  

;--------------------------------
;Variables

  Var MUI_TEMP
  Var STARTMENU_FOLDER

;--------------------------------
;Pages
  !insertmacro MUI_PAGE_LICENSE "COPYING.TXT"
  !insertmacro MUI_PAGE_COMPONENTS
  !insertmacro MUI_PAGE_DIRECTORY
  
  ;Start Menu Folder Page Configuration
  !define MUI_STARTMENUPAGE_REGISTRY_ROOT "HKCU" 
  ;!define MUI_STARTMENUPAGE_REGISTRY_KEY "Software\Software\Faster\ascii-design" 
  !define MUI_STARTMENUPAGE_REGISTRY_VALUENAME "Start Menu Folder"
  
  !insertmacro MUI_PAGE_STARTMENU Application $STARTMENU_FOLDER
  
  !insertmacro MUI_PAGE_INSTFILES
  
  !insertmacro MUI_UNPAGE_CONFIRM
  !insertmacro MUI_UNPAGE_INSTFILES

;--------------------------------
;Languages

  !insertmacro MUI_LANGUAGE "English" ;first language is the default language
  !insertmacro MUI_LANGUAGE "French"
  !insertmacro MUI_LANGUAGE "German"
  !insertmacro MUI_LANGUAGE "Spanish"
  !insertmacro MUI_LANGUAGE "SpanishInternational"
  !insertmacro MUI_LANGUAGE "SimpChinese"
  !insertmacro MUI_LANGUAGE "TradChinese"
  !insertmacro MUI_LANGUAGE "Japanese"
  !insertmacro MUI_LANGUAGE "Korean"
  !insertmacro MUI_LANGUAGE "Italian"
  !insertmacro MUI_LANGUAGE "Dutch"
  !insertmacro MUI_LANGUAGE "Danish"
  !insertmacro MUI_LANGUAGE "Swedish"
  !insertmacro MUI_LANGUAGE "Norwegian"
  !insertmacro MUI_LANGUAGE "NorwegianNynorsk"
  !insertmacro MUI_LANGUAGE "Finnish"
  !insertmacro MUI_LANGUAGE "Greek"
  !insertmacro MUI_LANGUAGE "Russian"
  !insertmacro MUI_LANGUAGE "Portuguese"
  !insertmacro MUI_LANGUAGE "PortugueseBR"
  !insertmacro MUI_LANGUAGE "Polish"
  !insertmacro MUI_LANGUAGE "Ukrainian"
  !insertmacro MUI_LANGUAGE "Czech"
  !insertmacro MUI_LANGUAGE "Slovak"
  !insertmacro MUI_LANGUAGE "Croatian"
  !insertmacro MUI_LANGUAGE "Bulgarian"
  !insertmacro MUI_LANGUAGE "Hungarian"
  !insertmacro MUI_LANGUAGE "Thai"
  !insertmacro MUI_LANGUAGE "Romanian"
  !insertmacro MUI_LANGUAGE "Latvian"
  !insertmacro MUI_LANGUAGE "Macedonian"
  !insertmacro MUI_LANGUAGE "Estonian"
  !insertmacro MUI_LANGUAGE "Turkish"
  !insertmacro MUI_LANGUAGE "Lithuanian"
  !insertmacro MUI_LANGUAGE "Slovenian"
  !insertmacro MUI_LANGUAGE "Serbian"
  !insertmacro MUI_LANGUAGE "SerbianLatin"
  !insertmacro MUI_LANGUAGE "Arabic"
  !insertmacro MUI_LANGUAGE "Farsi"
  !insertmacro MUI_LANGUAGE "Hebrew"
  !insertmacro MUI_LANGUAGE "Indonesian"
  !insertmacro MUI_LANGUAGE "Mongolian"
  !insertmacro MUI_LANGUAGE "Luxembourgish"
  !insertmacro MUI_LANGUAGE "Albanian"
  !insertmacro MUI_LANGUAGE "Breton"
  !insertmacro MUI_LANGUAGE "Belarusian"
  !insertmacro MUI_LANGUAGE "Icelandic"
  !insertmacro MUI_LANGUAGE "Malay"
  !insertmacro MUI_LANGUAGE "Bosnian"
  !insertmacro MUI_LANGUAGE "Kurdish"
  !insertmacro MUI_LANGUAGE "Irish"
  !insertmacro MUI_LANGUAGE "Uzbek"
  !insertmacro MUI_LANGUAGE "Galician"
  !insertmacro MUI_LANGUAGE "Afrikaans"
  !insertmacro MUI_LANGUAGE "Catalan"

;--------------------------------
;INstaller Icon
Icon "${NSISDIR}\Contrib\Graphics\Icons\orange-install.ico"

;--------------------------------
;Installer Sections

Section "ascii-design (Needed)" SecDummy

SectionIn RO
  SetOutPath "$INSTDIR"
  
  ;ADD YOUR OWN STUFF HERE!
  File ascii-design.exe
  File figlet.exe

  CreateDirectory "$INSTDIR\doc"
  SetOutPath "$INSTDIR\doc"
  File INSTALL.TXT
  File README.TXT
  File COPYING.TXT

  CreateDirectory "$INSTDIR\fonts"
  SetOutPath "$INSTDIR\fonts"
  File fonts\1row.flf
  File fonts\3-d.flf
  File fonts\3d_diagonal.flf
  File fonts\3x5.flf
  File fonts\4max.flf
  File fonts\5lineoblique.flf
  File fonts\acrobatic.flf
  File fonts\alligator.flf
  File fonts\alligator2.flf
  File fonts\alligator3.flf
  File fonts\alpha.flf
  File fonts\alphabet.flf
  File fonts\amc3line.flf
  File fonts\amc3liv1.flf
  File fonts\amcaaa01.flf
  File fonts\amcneko.flf
  File fonts\amcrazo2.flf
  File fonts\amcrazor.flf
  File fonts\amcslash.flf
  File fonts\amcslder.flf
  File fonts\amcthin.flf
  File fonts\amctubes.flf
  File fonts\amcun1.flf
  File fonts\arrows.flf
  File fonts\ascii_new_roman.flf
  File fonts\avatar.flf
  File fonts\B1FF.flf
  File fonts\banner.flf
  File fonts\banner3-D.flf
  File fonts\banner3.flf
  File fonts\banner4.flf
  File fonts\barbwire.flf
  File fonts\basic.flf
  File fonts\bear.flf
  File fonts\bell.flf
  File fonts\benjamin.flf
  File fonts\big.flf
  File fonts\bigchief.flf
  File fonts\bigfig.flf
  File fonts\binary.flf
  File fonts\block.flf
  File fonts\blocks.flf
  File fonts\bolger.flf
  File fonts\braced.flf
  File fonts\bright.flf
  File fonts\broadway.flf
  File fonts\broadway_kb.flf
  File fonts\bubble.flf
  File fonts\bulbhead.flf
  File fonts\calgphy2.flf
  File fonts\caligraphy.flf
  File fonts\cards.flf
  File fonts\catwalk.flf
  File fonts\chiseled.flf
  File fonts\chunky.flf
  File fonts\coinstak.flf
  File fonts\cola.flf
  File fonts\colossal.flf
  File fonts\computer.flf
  File fonts\contessa.flf
  File fonts\contrast.flf
  File fonts\cosmic.flf
  File fonts\cosmike.flf
  File fonts\crawford.flf
  File fonts\crazy.flf
  File fonts\cricket.flf
  File fonts\cyberlarge.flf
  File fonts\cybermedium.flf
  File fonts\cybersmall.flf
  File fonts\cygnet.flf
  File fonts\DANC4.flf
  File fonts\dancingfont.flf
  File fonts\decimal.flf
  File fonts\defleppard.flf
  File fonts\diamond.flf
  File fonts\dietcola.flf
  File fonts\digital.flf
  File fonts\doh.flf
  File fonts\doom.flf
  File fonts\dosrebel.flf
  File fonts\dotmatrix.flf
  File fonts\double.flf
  File fonts\doubleshorts.flf
  File fonts\drpepper.flf
  File fonts\dwhistled.flf
  File fonts\eftichess.flf
  File fonts\eftifont.flf
  File fonts\eftipiti.flf
  File fonts\eftirobot.flf
  File fonts\eftitalic.flf
  File fonts\eftiwall.flf
  File fonts\eftiwater.flf
  File fonts\epic.flf
  File fonts\fender.flf
  File fonts\filter.flf
  File fonts\fire_font-k.flf
  File fonts\fire_font-s.flf
  File fonts\flipped.flf
  File fonts\flowerpower.flf
  File fonts\fourtops.flf
  File fonts\fraktur.flf
  File fonts\funface.flf
  File fonts\funfaces.flf
  File fonts\fuzzy.flf
  File fonts\georgi16.flf
  File fonts\Georgia11.flf
  File fonts\ghost.flf
  File fonts\ghoulish.flf
  File fonts\glenyn.flf
  File fonts\goofy.flf
  File fonts\gothic.flf
  File fonts\graceful.flf
  File fonts\gradient.flf
  File fonts\graffiti.flf
  File fonts\greek.flf
  File fonts\heart_left.flf
  File fonts\heart_right.flf
  File fonts\henry3d.flf
  File fonts\hex.flf
  File fonts\hieroglyphs.flf
  File fonts\hollywood.flf
  File fonts\horizontalleft.flf
  File fonts\horizontalright.flf
  File fonts\ICL-1900.flf
  File fonts\impossible.flf
  File fonts\invita.flf
  File fonts\isometric1.flf
  File fonts\isometric2.flf
  File fonts\isometric3.flf
  File fonts\isometric4.flf
  File fonts\italic.flf
  File fonts\ivrit.flf
  File fonts\jacky.flf
  File fonts\jazmine.flf
  File fonts\jerusalem.flf
  File fonts\katakana.flf
  File fonts\kban.flf
  File fonts\keyboard.flf
  File fonts\knob.flf
  File fonts\konto.flf
  File fonts\kontoslant.flf
  File fonts\larry3d.flf
  File fonts\lcd.flf
  File fonts\lean.flf
  File fonts\letters.flf
  File fonts\lildevil.flf
  File fonts\lineblocks.flf
  File fonts\linux.flf
  File fonts\lockergnome.flf
  File fonts\lower.flc
  File fonts\madrid.flf
  File fonts\marquee.flf
  File fonts\maxfour.flf
  File fonts\merlin1.flf
  File fonts\merlin2.flf
  File fonts\mike.flf
  File fonts\mini.flf
  File fonts\mirror.flf
  File fonts\mnemonic.flf
  File fonts\modular.flf
  File fonts\morse.flf
  File fonts\morse2.flf
  File fonts\moscow.flf
  File fonts\mshebrew210.flf
  File fonts\muzzle.flf
  File fonts\nancyj-fancy.flf
  File fonts\nancyj-improved.flf
  File fonts\nancyj-underlined.flf
  File fonts\nancyj.flf
  File fonts\nipples.flf
  File fonts\nscript.flf
  File fonts\ntgreek.flf
  File fonts\null.flc
  File fonts\nvscript.flf
  File fonts\o8.flf
  File fonts\octal.flf
  File fonts\ogre.flf
  File fonts\oldbanner.flf
  File fonts\os2.flf
  File fonts\pawp.flf
  File fonts\peaks.flf
  File fonts\peaksslant.flf
  File fonts\pebbles.flf
  File fonts\pepper.flf
  File fonts\poison.flf
  File fonts\puffy.flf
  File fonts\puzzle.flf
  File fonts\pyramid.flf
  File fonts\rammstein.flf
  File fonts\rectangles.flf
  File fonts\red_phoenix.flf
  File fonts\relief.flf
  File fonts\relief2.flf
  File fonts\reverse.flf
  File fonts\roman.flf
  File fonts\rot13.flc
  File fonts\rot13.flf
  File fonts\rotated.flf
  File fonts\rounded.flf
  File fonts\rowancap.flf
  File fonts\rozzo.flf
  File fonts\runic.flf
  File fonts\runyc.flf
  File fonts\s-relief.flf
  File fonts\santaclara.flf
  File fonts\sblood.flf
  File fonts\script.flf
  File fonts\serifcap.flf
  File fonts\shadow.flf
  File fonts\shimrod.flf
  File fonts\short.flf
  File fonts\slant.flf
  File fonts\slide.flf
  File fonts\slscript.flf
  File fonts\small.flf
  File fonts\smallcaps.flf
  File fonts\smisome1.flf
  File fonts\smkeyboard.flf
  File fonts\smpoison.flf
  File fonts\smscript.flf
  File fonts\smshadow.flf
  File fonts\smslant.flf
  File fonts\smtengwar.flf
  File fonts\soft.flf
  File fonts\speed.flf
  File fonts\spliff.flf
  File fonts\stacey.flf
  File fonts\stampate.flf
  File fonts\stampatello.flf
  File fonts\standard.flf
  File fonts\starstrips.flf
  File fonts\starwars.flf
  File fonts\stellar.flf
  File fonts\stforek.flf
  File fonts\stop.flf
  File fonts\straight.flf
  File fonts\sub-zero.flf
  File fonts\swampland.flf
  File fonts\swan.flf
  File fonts\sweet.flf
  File fonts\tanja.flf
  File fonts\tengwar.flf
  File fonts\term.flf
  File fonts\test1.flf
  File fonts\thick.flf
  File fonts\thin.flf
  File fonts\threepoint.flf
  File fonts\ticks.flf
  File fonts\ticksslant.flf
  File fonts\tiles.flf
  File fonts\tinker-toy.flf
  File fonts\tombstone.flf
  File fonts\train.flf
  File fonts\trek.flf
  File fonts\tsalagi.flf
  File fonts\tubular.flf
  File fonts\twisted.flf
  File fonts\twopoint.flf
  File fonts\univers.flf
  File fonts\upper.flc
  File fonts\usaflag.flf
  File fonts\varsity.flf
  File fonts\wavy.flf
  File fonts\weird.flf
  File fonts\wetletter.flf
  File fonts\whimsy.flf
  File fonts\wow.flf


  ;Store installation folder
  WriteRegStr HKCU "Software\Faster\ascii-design" "" $INSTDIR

  ; Write the uninstall keys for Windows
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\ascii-design" "DisplayName" "ascii-design uninstaller"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\ascii-design" "UninstallString" '"$INSTDIR\uninstall.exe"'
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\ascii-design" "NoModify" 1
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\ascii-design" "NoRepair" 1
  WriteUninstaller "uninstall.exe"
  
  ;Create uninstaller
  WriteUninstaller "$INSTDIR\Uninstall.exe"
  
  !insertmacro MUI_STARTMENU_WRITE_BEGIN Application
    
    ;Create shortcuts
    CreateDirectory "$SMPROGRAMS\$STARTMENU_FOLDER\ascii-design"
    CreateShortCut "$SMPROGRAMS\$STARTMENU_FOLDER\ascii-design\Uninstall.lnk" "$INSTDIR\Uninstall.exe"
    CreateShortCut "$SMPROGRAMS\$STARTMENU_FOLDER\ascii-design\ascii-design.lnk" "$INSTDIR\ascii-design.exe"
    CreateShortCut "$SMPROGRAMS\$STARTMENU_FOLDER\ascii-design\Licenza.lnk   "$INSTDIR\doc\COPYING.txt"
    CreateShortCut "$SMPROGRAMS\$STARTMENU_FOLDER\ascii-design\readme.lnk   "$INSTDIR\doc\README.TXT"
    CreateShortCut "$SMPROGRAMS\$STARTMENU_FOLDER\ascii-design\install.lnk   "$INSTDIR\doc\INSTALL.TXT"
    CreateShortCut "$DESKTOP\ascii-design.lnk" "$INSTDIR\ascii-design.exe"

!insertmacro MUI_STARTMENU_WRITE_END

SectionEnd

;Section Qt libs
Section "Qt-4.4.0 Runtime libraries (needed if Qt-4 in not installed)"

;SectionIn
  SetOutPath "$INSTDIR"

  FILE C:\lib\Qt\4.4.0\bin\mingwm10.dll
  FILE C:\lib\Qt\4.4.0\bin\QtCore4.dll
  FILE C:\lib\Qt\4.4.0\bin\QtGui4.dll

SectionEnd
 
;--------------------------------
;Uninstaller Section

UninstallIcon "${NSISDIR}\Contrib\Graphics\Icons\orange-uninstall.ico"

Section "Uninstall"
  ;ADD YOUR OWN STUFF HERE!

  Delete "$INSTDIR\Uninstall.exe"

  RMDir /r "$INSTDIR"
  
  !insertmacro MUI_STARTMENU_GETFOLDER Application $MUI_TEMP
    
  Delete "$SMPROGRAMS\$MUI_TEMP\Uninstall.lnk"
  Delete "$DESKTOP\ascii-design.lnk"
  
  ;Delete empty start menu parent diretories
  StrCpy $MUI_TEMP "$SMPROGRAMS\$MUI_TEMP\ascii-design"
 
  startMenuDeleteLoop:
    RMDir /r $MUI_TEMP
    GetFullPathName $MUI_TEMP "$MUI_TEMP\ascii-design"

;Cancella se fAsTeR è vuoto
!insertmacro MUI_STARTMENU_GETFOLDER Application $MUI_TEMP
  StrCpy $MUI_TEMP "$SMPROGRAMS\$MUI_TEMP"
 
    RMDir  $MUI_TEMP
    GetFullPathName $MUI_TEMP "$MUI_TEMP"

    
    IfErrors startMenuDeleteLoopDone
  
    StrCmp $MUI_TEMP $SMPROGRAMS startMenuDeleteLoopDone startMenuDeleteLoop
  startMenuDeleteLoopDone:

DeleteRegKey HKCU "Software\Software\Faster\ascii-design"
DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\ascii-design"
SectionEnd