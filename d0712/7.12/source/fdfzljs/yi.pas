const n=400000;k=28;p=1 shl k;
var a:array[0..n]of longint;
    st:ansistring;
    nn,b1,b2,b3,b4,ans:longint;
    t1,t2:text;
procedure jin();
var g1,g2:longint;
begin
  for g1:=0 to a[n]-1 do begin
    a[g1+1]:=a[g1+1]+a[g1] div p;
    a[g1]:=a[g1] mod p;
  end;
  while a[a[n]]>=p do begin
    a[a[n]+1]:=a[a[n]] div p;
    a[a[n]]:=a[a[n]] mod p;
    a[n]:=a[n]+1;
  end;
end;
procedure ti(f1:longint);
var g1,g2:longint;
begin
  for g1:=0 to a[n] do a[g1]:=a[g1]*f1;
  inc(a[0]);
  jin();
end;
function mo2():longint;
var ans,g1,g2,g3:longint;
begin
  g1:=0;
  while (((a[0] shr g1)and 1)=0)and(g1<k) do g1:=g1+1;
  if g1=0 then exit(0);
  for g2:=0 to a[n] do begin
    a[g2]:=a[g2]shr g1;
    a[g2]:=a[g2] or((a[g2+1] and ((1 shl g1)-1))shl(k-g1));
  end;
  while a[a[n]]=0 do dec(a[n]);
  exit(g1);
end;
begin
  assign(t1,'yi.in');reset(t1);
  assign(t2,'yi.out');rewrite(t2);
  fillchar(a,sizeof(a),0);
  readln(t1,st);
  b2:=0;
  for b1:=length(st) downto 1 do begin
    a[b2 div k]:=a[b2 div k] or ((ord(st[b1])-ord('0')) shl (b2 mod k)) ;
    b2:=b2+1;
  end;
  a[n]:=(b2-1) div k ;
  ans:=0;
  while not(odd(a[0])) do ans:=ans+mo2;

  while not((a[n]=0)and(a[0]=1)) do begin
    ti(3);ans:=ans+1;
    while not(odd(a[0])) do ans:=ans+mo2;
  end;
  writeln(t2,ans);
  close(t1);
  close(t2);
end.
