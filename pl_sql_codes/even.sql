DECLARE
	NO NUMBER(6);
	NO3 NUMBER(6);
	tp number(1);
	SIZEE NUMBER(2) :=0;
	SUM NUMBER(7):=0;
BEGIN
	NO := &NO;
	NO3 := NO;
	WHILE  NO3> 0
	LOOP
		tp:=mod(SIZEE,2);
		if tp=0 then
			SUM:=SUM+mod(NO3,10);
		 D IF;
		NO3 := NO3/10 ;
		SIZEE:=SIZEE+1;
	END LOOP;
	DBMS_OUTPUT.PUT_LINE('SUM IS' ||SUM);
END;
/
