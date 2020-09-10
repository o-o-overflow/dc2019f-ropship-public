#!/bin/bash


TMPFOLDER="/dev/shm/ropship"
echo "$TMPFOLDER"

#rm -r "$TMPFOLDER" # we don't want to delete /dev/shm/ropship/inputs

#these 2 should be already existing
mkdir "$TMPFOLDER"
INPUTSFOLDER="$TMPFOLDER/inputs"
mkdir "$INPUTSFOLDER"

CHAINSFOLDER="$TMPFOLDER/chains"
rm "$TMPFOLDER/rnd.bin"
rm "$TMPFOLDER/states"
rm -r "$CHAINSFOLDER"
mkdir "$CHAINSFOLDER"


echo "==="
if [[ "$1" == "simulated" ]]; then
    rm -r "$INPUTSFOLDER"
    mkdir "$INPUTSFOLDER"
    ./create_solutions.py
    ./compile_all.sh
    echo "$TMPFOLDER/inputs/"
    cp -a solutions/* "$TMPFOLDER/inputs/"
    cp solutions/heavyleft "$TMPFOLDER/inputs/team7"
    cp solutions/heavyleft_seccomp "$TMPFOLDER/inputs/team8"
    cp solutions/heavyleft_seccomprop "$TMPFOLDER/inputs/team9"

    DEFCONROUND="134"
    TEAMS="1-434743_2-484954434f4ee29a9442464b_3-687870_4-4b6169734861636b20476f4e_5-6d6861636b65726f6e69_6-4f4f4f_7-72303074696d656e74617279_8-72336b61706967_9-73616172736563_10-53616d75726169_11-5361756572636c6f7564_12-53656f756c2b426164417373_13-5368656c6c7068697368_14-5465612044656c69766572657273_15-546f6b796f5765737465726e73_17-412a302a45"
    echo "==="
    #sleep 10

else
    DEFCONROUND="$1"
    TEAMS="$2"
fi


python3 -u simulator.py "$DEFCONROUND" "$TEAMS" 2>&1 | tee -a "/var/tmp/ropship.log"

