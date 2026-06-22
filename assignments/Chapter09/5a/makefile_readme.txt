--
1. make is a rules engine.
   of the format
	 [target]: [<dep1> <dep2>.....]
	 tab<action-line to convert deps into targets>
	 tab<action-line to convert deps into targets>
	 tab<action-line to convert deps into targets>
	 tab<action-line to convert deps into targets>
	 tab<action-line to convert deps into targets>
	 tab<action-line to convert deps into targets>
	 .
	 .
	 .
	 -- last line of the rules set: at this point .. steps for the target are achieved.
   -- PHONY_TARGET: [ <target1> <target2> ... ]
                  .. mainly for documentation .. to indicate that nothing physical exists with the target name
										- e.g. make build
--
2. default rules .. by running "make -p"
   and, compile without a makefile  .. because of default rules.
--
3. every action-line in the makefile, is a separate subshell, by itself.
   meaning that the args/values set on an action line do not carryover to the next line.
--
