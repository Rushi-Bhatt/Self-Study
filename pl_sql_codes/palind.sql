DECLARE
	NO NUMBER(6);
	NO2 NUMBER(6) :=0;
	NO3 NUMBER(6);
	SIZEE NUMBER(2) :=0;
BEGIN
	NO := &NO;
	NO3 := NO;
	WHILE  NO3> 0
	LOOP
		NO3 := NO3/10 ;
		SIZEE:=SIZEE+1;
	END LOOP;
	NO3:=NO;
	WHILE  NO3> 0
	LO 
		NO2:=mod(NO3,10)*power(10,SIZEE-1)+NO2;
		NO3 := NO3/10 ;
		SIZEE:=SIZEE-1;
	END LOOP;
	if NO2=NO
		then DBMS_OUTPUT.PUT_LINE('Palindrome...');
	else DBMS_OUTPUT.PUT_LINE('Not a Palindrome...');
	end if;
END;
/
