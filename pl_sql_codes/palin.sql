DECLARE
	NO NUMBER(6);
	NO2 NUMBER(6) :=0;
	NO3 NUMBER(6);
	SIZE NUMBER(2);
BEGIN
	NO := &NO;
	NO3 := NO;
	WHILE  NO3> 0
	LOOP
		NO2:=mode(NO3,10)*pow(10,SIZE)+NO2;
		NO3 := NO3/10 ;
		SIZE=SIZE-1;
	END LOOP; if NO3==NO1
		then DBMS_OUTPUT.PUT_LINE('Palindrome...');
	else DBMS_OUTPUT.PUT_LINE('Not Palindrome...');
	end if;
END;
/
