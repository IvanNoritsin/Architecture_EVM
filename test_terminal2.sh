CLR="\E[H\E[J"
ENTER_ALT_MODE="\E(0"
EXIT_ALT_MODE="\E(B"
ACS_CKBOARD="a"
ACS_ULCORNER="l"
ACS_URCORNER="k"
ACS_LLCORNER="m"
ACS_LRCORNER="j"
ACS_HLINE="q"
ACS_VLINE="x"

echo -e "$CLR"

echo -e "\E[10;5H$ENTER_ALT_MODE$ACS_ULCORNER$EXIT_ALT_MODE"
echo -e "\E[10;14H$ENTER_ALT_MODE$ACS_URCORNER$EXIT_ALT_MODE"
echo -e "\E[19;5H$ENTER_ALT_MODE$ACS_LLCORNER$EXIT_ALT_MODE"
echo -e "\E[19;14H$ENTER_ALT_MODE$ACS_LRCORNER$EXIT_ALT_MODE"

for ((i = 0; i < 8; i++)); do
    echo -e "\E[10;$((6+i))H$ENTER_ALT_MODE$ACS_HLINE$EXIT_ALT_MODE"
    echo -e "\E[19;$((6+i))H$ENTER_ALT_MODE$ACS_HLINE$EXIT_ALT_MODE"
done

for ((i = 0; i < 8; i++)); do
    echo -e "\E[$((11+i));5H$ENTER_ALT_MODE$ACS_VLINE$EXIT_ALT_MODE"
    echo -e "\E[$((11+i));14H$ENTER_ALT_MODE$ACS_VLINE$EXIT_ALT_MODE"
done

for ((i = 0; i < 6; i++)); do
    echo -e "\E[11;$((7+i))H$ENTER_ALT_MODE$ACS_CKBOARD$EXIT_ALT_MODE"
    echo -e "\E[18;$((7+i))H$ENTER_ALT_MODE$ACS_CKBOARD$EXIT_ALT_MODE"
done

for ((i = 0; i < 6; i++)); do
    echo -e "\E[$((12+i));7H$ENTER_ALT_MODE$ACS_CKBOARD$EXIT_ALT_MODE"
    echo -e "\E[$((12+i));12H$ENTER_ALT_MODE$ACS_CKBOARD$EXIT_ALT_MODE"
done


echo -ne "\E[20;1H"