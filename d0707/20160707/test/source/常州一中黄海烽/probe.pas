const mn=2000;
var
   ii,oo,c,ls,kk:array[0..2010] of longint;
   fi,fo:array[0..2010] of boolean;
   i,j,n,t,ans,id,st,lj,k:longint;
   p:boolean;
   ch:char;

procedure setin;
begin
    assign(input,'probe.in');
    assign(output,'probe.out');
    reset(input);rewrite(output);
end;

procedure outit;
begin
    close(input);close(output);
end;

procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
    i:=l;j:=r;x:=ls[(l+r)>>1];
    repeat
       while ls[i]<x do i:=i+1;
       while ls[j]>x do j:=j-1;
       if not (i>j) then
       begin
           y:=ls[i];ls[i]:=ls[j];ls[j]:=y;
           y:=c[i];c[i]:=c[j];c[j]:=y;
           y:=kk[i];kk[i]:=kk[j];kk[j]:=y;
           i:=i+1;j:=j-1;
       end;
    until i>j;
    if i<r then sort(i,r);
    if l<j then sort(l,j);
end;

begin
    setin;
    readln(t);
    for k:=1 to t do
    begin
        readln(n);ans:=0;
        fillchar(c,sizeof(c),0);
        fillchar(kk,sizeof(kk),0);
        fillchar(ls,sizeof(ls),0);
        ii[0]:=0;oo[0]:=0;p:=true;
        for i:=1 to n do fi[i]:=true;
        for i:=1 to n do fo[i]:=true;
        for i:=1 to n do
        begin
            readln(ch,id);
            if ch='E' then
            begin
                if id=0 then
                begin
                    inc(ii[0]);
                    ii[ii[0]]:=i;
                end
                else
                begin
                    if c[id]<=0 then
                    begin
                        inc(ans);if c[id]=0 then kk[id]:=1 else kk[id]:=0;
                        c[id]:=1;ls[id]:=i;
                    end
                    else
                    begin
                        p:=false;
                        for j:=1 to oo[0] do
                         if fo[j] and(oo[j]>ls[id]) then
                         begin
                             p:=true;
                             fo[j]:=false;
                             c[id]:=1;ls[id]:=i;
                         end;
                    end;
                end;
            end
            else
            begin
                if id=0 then
                begin
                   inc(oo[0]);
                   oo[oo[0]]:=i;
                end
                else
                begin
                    if c[id]>=0 then
                    begin
                        dec(ans,c[id]);if c[id]=0 then kk[id]:=1 else kk[id]:=0;
                        c[id]:=-1;ls[id]:=i;
                    end
                    else
                    begin
                        p:=false;
                        for j:=1 to ii[0] do
                         if fi[j] and(ii[j]>ls[id]) then
                         begin
                             p:=true;
                             fi[j]:=false;
                             c[id]:=-1;ls[id]:=i;
                         end;
                    end;

                end;
            end;
            //if not p then break;
        end;
        i:=1;j:=1;
        while (i<=ii[0])and(j<=oo[0]) do
        begin
            while (i<=ii[0])and(not fi[i]) do inc(i);
            while (j<=oo[0])and((not fo[j])or(ii[i]>oo[j])) do inc(j);
            if (i>ii[0])or(j>oo[0]) then break;
            fi[i]:=false;fo[j]:=false;inc(i);inc(j);
        end;
        sort(1,mn);st:=mn+1;
        for i:=1 to mn do if ls[i]>0 then begin st:=i;break;end;
        for i:=1 to ii[0] do
         if fi[i] then
         begin
             for j:=st to mn do
              if (c[j]=-1) then
              begin
                  if ls[j]<ii[i] then
                  begin
                      inc(ans);c[j]:=1;ls[j]:=ii[i];fi[i]:=false;
                  end else
                  begin
                      if kk[j]=1 then fi[i]:=false;
                  end;
                  if not fi[i] then break;
              end;
         end;
        sort(1,mn);st:=mn+1;
        for i:=1 to mn do if ls[i]>0 then begin st:=i;break;end;
        for i:=1 to oo[0] do
         if fo[i] then
         begin
             for j:=st to mn do
              if (c[j]=1) then
              begin
                  if ls[j]<oo[i] then
                  begin
                      dec(ans);c[j]:=-1;ls[j]:=oo[i];fo[i]:=false;
                  end else
                  begin
                      if kk[j]=1 then fo[i]:=false;
                  end;
                  if not fo[i] then break;
              end;
         end;
        for i:=1 to ii[0] do if fi[i] then inc(ans);
        if p then writeln(ans) else writeln('OTHER');
    end;
    outit;
end.
