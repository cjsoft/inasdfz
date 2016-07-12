var a:array [0..10001] of integer; len,i,tmp:longint; ans:int64; ch:char;

procedure m1;
var i,t:longint;
begin
  for i:=1 to len do a[i]:=a[i]*3;
  t:=0;
  for i:=1 to len do
  begin
    a[i]:=a[i]+t;
    t:=a[i] div 2;
    a[i]:=a[i] mod 2;
  end;
  while t>0 do
  begin
    inc(len); a[len]:=t; t:=a[len] div 2; a[len]:=a[len] mod 2;
  end;
end;

procedure m2;
var i,t:longint;
begin
  a[1]:=a[1]+1;
  t:=0;
  for i:=1 to len do
  begin
    a[i]:=a[i]+t;
    t:=a[i] div 2;
    a[i]:=a[i] mod 2;
  end;
  while t>0 do
  begin
    inc(len); a[len]:=t; t:=a[len] div 2; a[len]:=a[len] mod 2;
  end;
end;

procedure m3;
var i,t:longint;
begin
  for i:=1 to len-1 do a[i]:=a[i+1]; dec(len);
end;

begin
  assign(input,'yi.in'); assign(output,'yi.out');
  reset(input); rewrite(output);

  len:=0;
  while not eoln do
  begin
    inc(len); read(ch); a[len]:=ord(ch)-48;
  end;

  for i:=1 to len div 2 do
  begin
    tmp:=a[i]; a[i]:=a[len-i+1]; a[len-i+1]:=tmp;
  end;
  ans:=0;
  while len>1 do
  begin
    if a[1]=1 then
    begin
      m1; m2; inc(ans);
    end
    else
    begin
      m3; inc(ans);
    end;
  end;

  writeln(ans);

  close(input); close(output);
end.