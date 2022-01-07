#both works
echo "dbus-send --system --type=signal --dest=org.sdbuscpp.add /org/sdbuscpp/ext org.sdbuscpp.ext.ext"
dbus-send --system  --type=signal --dest=org.sdbuscpp.add /org/sdbuscpp/ext org.sdbuscpp.ext.ext
