function y = fixarr(x)

y ='{ ';
if length(x)>1,
    for i=1:(length(x)-1),
        y = [y,num2str(x(i)),', '];
        i=i+1;
    end
    y = [y,num2str(x(i)),' }'];
    
else
    y=[y,num2str(x{1}),' }'];
end
%disp(y);
return