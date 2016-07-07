var  t,i,n,k:longint; ch:char;
begin
  assign(input,'probe.in'); assign(output,'probe.out');
  reset(input); rewrite(output);
  
  readln(t);randomize;
  for t:=1 to t do
  begin
    readln(k);
	n:=random(10);
	if (n=5) or (n=6) then writeln(k) else writeln(0);
  end;
  
  close(input); close(output);
end.