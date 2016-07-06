var
   i,n,t,ans,e,p,y:longint;
   fa,zt,g,a,ot,ne:array[0..101001] of longint;

procedure setin;
begin
    assign(input,'ah.in');
    assign(output,'ah.out');
    reset(input);rewrite(output);
end;

procedure outit;
begin
    close(input);close(output);
end;

procedure add(x,y:longint);
begin
    ot[e]:=y;ne[e]:=g[x];g[x]:=e;e:=e+1;
end;

procedure dfs(x:longint);
var p,y:longint;
begin
    p:=g[x];
    while p<>-1 do
    begin
        y:=ot[p];
        dfs(y);
        if zt[y]>0 then inc(zt[x]);
        if zt[y]<0 then dec(zt[x]);
        p:=ne[p];
    end;
end;

procedure count(x:longint);
var p:longint;
begin
    if zt[x]<0 then exit;
    if (g[x]=-1)and(zt[x]=0) then begin inc(ans);a[ans]:=x;end;
    p:=g[x];
    while p<>-1 do
    begin
        count(ot[p]);
        p:=ne[p];
    end;
end;

procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
    i:=l;j:=r;x:=a[(l+r)>>1];
    repeat
        while a[i]<x do i:=i+1;
        while a[j]>x do j:=j-1;
        if not (i>j) then
        begin
            y:=a[i];a[i]:=a[j];a[j]:=y;
            i:=i+1;j:=j-1;
        end;
    until i>j;
    if i<r then sort(i,r);
    if l<j then sort(l,j);
end;

begin
    setin;
    read(t);
    for t:=1 to t do
    begin
        read(n);zt[0]:=0;
        for i:=1 to n do g[i]:=-1;e:=0;
        for i:=1 to n do begin read(fa[i]);add(fa[i],i);end;
        for i:=1 to n do begin read(zt[i]);if zt[i]<=0 then zt[i]:=-1-zt[i];end;
        dfs(1);
        if zt[1]>0 then begin writeln(-1);continue;end;
        if zt[1]<0 then
        begin
            ans:=0;
            for i:=1 to n do if (g[i]=-1)and(zt[i]=0) then begin inc(ans);a[ans]:=i;end;
            write(ans);
            for i:=1 to ans do write(' ',a[i]);writeln;
            continue;
        end;
        ans:=0; count(1);
        sort(1,ans);
        write(ans);
        for i:=1 to ans do write(' ',a[i]);writeln;
    end;
    outit;
end.
