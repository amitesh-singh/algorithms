#both works
#echo "dbus-send --system --type=signal / org.sdbuscpp.ext.ext"
#dbus-send --system --type=signal / org.sdbuscpp.ext.ext
echo "dbus-send --system --type=signal /org/sdbuscpp/ext org.sdbuscpp.ext.ext"
dbus-send --system --type=signal /org/sdbuscpp/ext org.sdbuscpp.ext.ext
