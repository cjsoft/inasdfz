var n,i,m,l,r,t:longint; a,b:array [0..100001] of int64; ans:int64;

procedure swap(id:longint);
var temp:int64;
begin
  dec(ans,a[id]); inc(ans,b[id]);
  temp:=a[id]; a[id]:=b[id]; b[id]:=temp;
end;

begin
  assign(input,'name.in'); assign(output,'name.out');
  reset(input); rewrite(output);

  readln(n); ans:=0;
  for i:=1 to n do begin read(a[i]); inc(ans,a[i]); end;
  for i:=1 to n do read(b[i]);
  readln(m);
  for m:=1 to m do
  begin
    readln(l,r,t);
    for i:=l to r do
    begin
      if a[i]<=t then swap(i);
    end;
  end;
  writeln(ans);

  close(input); close(output);
end.