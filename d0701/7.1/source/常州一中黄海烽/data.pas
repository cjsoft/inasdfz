var
   an:array[0..1500000] of string;
   a:array[0..100] of int64;
   i,j,x,n,t,l,r,k,m,cz:longint;
   tt,ans:int64;

procedure setin;
begin
    assign(input,'data.in');
    assign(output,'data.out');
    reset(input);rewrite(output);
end;

procedure outit;
begin
    close(input);close(output);
end;

procedure sort(l,r:longint);
var i,j:longint;x,y:string;
begin
    i:=l;j:=r;x:=an[(l+r)>>1];
    repeat
        while an[i]<x do i:=i+1;
        while an[j]>x do j:=j-1;
        if not (i>j) then
        begin
            y:=an[i];an[i]:=an[j];an[j]:=y;
            i:=i+1;j:=j-1;
        end;
    until i>j;
    if i<r then sort(i,r);
    if l<j then sort(l,j);
end;

procedure dfs(now:longint;ss:string);
var i:longint;
begin
    inc(tt);an[tt]:=ss;
    for i:=now+1 to r do dfs(i,ss+chr(a[i]+48));
end;

begin
    setin;
    read(t);
    for t:=1 to t do
    begin
        read(n,k,m);
        for i:=1 to n do read(a[i]);
        for i:=1 to m do
        begin
            read(cz);
            case cz of
            1:
              begin
                  read(l,r,x);
                  for j:=l to r do a[j]:=(a[j]+x) mod k;
              end;
            2:
              begin
                  read(l,r,x);
                  for j:=l to r do a[j]:=(a[j]*x) mod k;
              end;
            3:
              begin
                  read(l,r);
                  tt:=0;
                  for j:=l to r do dfs(j,chr(a[j]+48));
                  sort(1,tt);
                  ans:=tt;
                  for j:=2 to tt do if an[j]=an[j-1] then dec(ans);
                  writeln(ans mod 998244353);
              end;
            end;
        end;
    end;
    outit;
end.
