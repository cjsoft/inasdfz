const m=1073741824;
var a,b,c,i,j,k,t:longint; n,ans:int64;
begin
  assign(input,'skyfall.in'); assign(output,'skyfall.out');
  reset(input); rewrite(output);

  readln(a,b,c); ans:=0;
  for i:=1 to a do
    for j:=1 to b do
	  for k:=1 to c do
	  begin
	    n:=i*j*k;
		for t:=1 to trunc(sqrt(n)) do
		begin
		  if (n mod t=0) then
		  begin
		    if t*t=n then inc(ans) else inc(ans,2);
                    ans:=ans mod m;
		  end;
		end;
	  end;
  writeln(ans);

  close(input); close(output);
end.
