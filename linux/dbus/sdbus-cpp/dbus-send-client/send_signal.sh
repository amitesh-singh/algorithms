dbus-send --system  --type=signal --dest=org.sdbuscpp.add /org/sdbuscpp/ext org.sdbuscpp.ext.ext
dbus-send --system  --type=signal --dest=org.sdbuscpp.add /org/sdbuscpp/ext org.sdbuscpp.ext.ext2 string:"ext2"
dbus-send --system  --type=signal --dest=org.sdbuscpp.add /org/sdbuscpp/ext org.sdbuscpp.ext.ext3 string:"ext3" int32:5
dbus-send --system  --type=signal --dest=org.sdbuscpp.add /org/sdbuscpp/ext org.sdbuscpp.ext.ext4 string:"ext4" int32:5 array:int32:5,6,7
dbus-send --system  --type=signal --dest=org.sdbuscpp.add /org/sdbuscpp/ext org.sdbuscpp.ext.ext5 string:"ext5" int32:5 array:byte:5,6,7
