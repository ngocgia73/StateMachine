/* demo how to use stamachine with c programming use function pointer */

- assuming that we have two led : 
le1 -> green led 
led -> red led 

- we'll use another thread to send event to main thread . just change state machine while new event was sent 
=== STATE MACHINE == 
state 1 :  
	+ led 1 => off 
	+ led 2 => off
state 2 : 
	+ led 1 => on 
	+ led 2 => on 
state 3 : 
	+ led 1 => off
	+ led 2 => on 
state 4 :
	+ led 1 => on
	+ led 2 => off

=== HANDLE COMMAND === 
command  = 1  => state 1
command  = 2  => state 2
command  = 3  => state 3
command  = 4  => state 4
