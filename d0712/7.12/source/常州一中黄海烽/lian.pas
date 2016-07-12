var
   i,n,p,q,tm,tot,j:longint;
   xby,a,b:array[0..2010] of longint;
   le,ri:array[0..4001000] of longint;
   c:array[0..10000000] of longint;

procedure setin;
begin
    assign(input,'lian.in');
    assign(output,'lian.out');
    reset(input);rewrite(output);
end;

procedure outit;
begin
    close(input);close(output);
end;

function check(x1,x2,y1,y2:longint):boolean;
var i:longint;
begin
    if (x1=y1)and(x2=y2) then exit(false);
    if (x1<=y1)and(x2>=y2) then exit(true);
    if (x1>=y1)and(x2<=y2) then exit(false);
    for i:=1 to tm do xby[i]:=0;
    if (x2>y1)and(x1<y1) then begin i:=x2;x2:=y1;y1:=i;dec(x2);inc(y1);end;
    if (y2>x1)and(y1<x1) then begin i:=y2;y2:=x1;x1:=i;dec(y2);inc(x1);end;
    for i:=x1 to x2 do inc(xby[c[a[i]]]);
    for i:=y1 to y2 do dec(xby[c[a[i]]]);
    for i:=1 to tm do
    begin
        if xby[i]>0 then exit(true);
        if xby[i]<0 then exit(false);
    end;
    if x1<y1 then exit(true);
    exit(false);
end;

procedure sort(l,r:longint);
var i,j,x1,x2,x3,y:longint;
begin
    i:=l;j:=r;x1:=le[(l+r)>>1];x2:=ri[(l+r)>>1];
    repeat
        while check(le[i],ri[i],x1,x2) do inc(i);
        while check(x1,x2,le[j],ri[j]) do dec(j);
        if not (i>j) then
        begin
            y:=le[i];le[i]:=le[j];le[j]:=y;
            y:=ri[i];ri[i]:=ri[j];ri[j]:=y;
            i:=i+1;j:=j-1;
        end;
    until i>j;
    if i<r then sort(i,r);
    if l<j then sort(l,j);
end;

procedure sort2(l,r:longint);
var i,j,x,y:longint;
begin
    i:=l;j:=r;x:=b[(l+r)>>1];
    repeat
        while b[i]<x do i:=i+1;
        while b[j]>x do j:=j-1;
        if not (i>j) then
        begin
            y:=b[i];b[i]:=b[j];b[j]:=y;
            i:=i+1;j:=j-1;
        end;
    until i>j;
    if i<r then sort2(i,r);
    if l<j then sort2(l,j);
end;

begin
    setin;
    read(n,p,q);
    for i:=1 to n do read(a[i]);
    for i:=1 to n do b[i]:=a[i];
    sort2(1,n);
    tm:=0;b[0]:=-maxlongint;
    for i:=1 to n do if b[i]<>b[i-1] then begin inc(tm);c[b[i]]:=tm;end;
    tot:=0;
    for i:=1 to n do
     for j:=n downto i do
     begin inc(tot);le[tot]:=i;ri[tot]:=j;end;
    sort(1,tot);
    for i:=p to q do writeln(le[i],' ',ri[i]);

    outit;
end.
