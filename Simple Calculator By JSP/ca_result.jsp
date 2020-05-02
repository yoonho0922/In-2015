<%@ page contentType="text/html; charset=UTF-8"%>
<%
	int fir = Integer.parseInt(request.getParameter("fir"));
	int sec = Integer.parseInt(request.getParameter("fir"));
	int ca = Integer.parseInt(request.getParameter("ca"));
	int result = 0;
	String s= "";
	
	switch(ca){
		case 1:	 result = fir+sec;
		s = "＋";
		break;
		case 2:  result = fir-sec;
		s = "－";
		break;
		case 3:  result = fir*sec;
		s = "×";
		break;
		case 4:  result = fir/sec;
		s = "÷";
		
	
	}

%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>사칙연산기</title>
</head>
<body>
<h1>간단한 사칙연산기</h1>

	<%=fir %> <%=s %> <%=sec %> = <%=result %>


</body>
</html>

