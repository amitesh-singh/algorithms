refer calc/ for brush up


<!-- allow ami can own the service -->
  <policy user="ami">
    <allow own="org.sdbuscpp.add"/>
    <allow send_destination="org.sdbuscpp.add" />
  </policy>

  then you can run the service as a non-root user 'ami'

