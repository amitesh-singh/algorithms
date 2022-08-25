The promise:
1. is the data sender
2. can send many futures
3. can send values, exceptions, and notifications

The future:
1. is the data reciever
2. calls get and is eventually blocked
3 ~future() { get(); }

