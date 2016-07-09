var s:array [0..5001] of char; n,i,j,k:longint;
    next:array [0..5001,0..5001] of longint;
	mx,st:array [0..5001] of longint;
begin
  assign(input,'encrypt.in'); assign(output,'encrypt.out');
  reset(input); rewrite(output);

  n:=0;
  while not eoln do
  begin
    inc(n); read(s[n]);
  end;

  fillchar(next,sizeof(next),0);
  for i:=1 to n do
  begin
    k:=i-1; next[i,i]:=k;
    for j:=i+1 to n do
	begin
	  k:=next[i,j-1];
	  while (s[k+1]<>s[j]) and (k>i-1) do
	  begin
	    k:=next[i,k];
	  end;
          if s[k+1]=s[j] then next[i,j]:=k+1 else next[i,j]:=i-1;
	end;
  end;
  {for i:=1 to n do
  begin
    for j:=1 to n do write(next[i,j],' ');
	writeln;
  end;}
  fillchar(st,sizeof(st),0);
  fillchar(mx,sizeof(mx),0);
  for i:=1 to n do
    for j:=i+1 to n do
	begin
	  k:=next[i,j]-i+1;
	  if k>mx[j-k+1] then begin mx[j-k+1]:=k; st[j-k+1]:=i; end;
	end;

  i:=1; 
  if mx[i]=0 then write(-1,' ',ord(s[i])) else 
  begin write(mx[i],' ',st[i]);inc(i,mx[i]-1); end;
  while i<n do
  begin
    inc(i);
	if mx[i]=0 then write(' ',-1,' ',ord(s[i])) else 
    begin write(' ',mx[i],' ',st[i]-1);inc(i,mx[i]-1); end;
  end;
  writeln;

  close(input); close(output);
end.
