DECLARE
	NO NUMBER(4);
	I NUMBER(4);
	FACT NUMBER(4);
BEGIN
	NO := &NO;
	I := NO;
	FACT := 1;
	WHILE  I >= 1
	LOOP
		FACT := FACT * I;
		I := I - 1;
	END LOOP;
	DBMS_OUTPUT.PUT_LINE('fact is' ||FACT);
END;
/ 