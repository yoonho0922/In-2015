<%@ page contentType="text/html; charset=UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>사칙연산기</title>

<script type="text/javascript">

	function sendIt(){
		
		
		if(!document.myForm.fir.value){
			alert("값을 입력하세요!");
			f.userId.focus();
			return;
		}
		if(!document.myForm.sec.value){
			alert("값을 입력하세요!");
			f.userId.focus();
			return;
		}
		document.myForm.submit();
	}

	</script>

</head>


<body>

<h1>간단한 사칙연산기</h1>

<form action="ca_result.jsp" name="myForm"method="post">

		<table border="1">
			<tr>
 				<td>
 					<input type="text" name="fir">
 				</td>
 				<td>
					<select name="ca" >
						<option value="1">＋<option/>
						<option value="2">－<option/>
						<option value="3">×<option/>
						<option value="4">÷<option/>	
					</select>	
				<td>
					<input type="text" name="sec">
				</td>
			</tr>
			<tr>
				<td align="center" colspan="3">
					<input type="button" value="결과보기" onclick="sendIt();"/>
				</td>
			</tr>
		</table> 





</form>


</body>
</html>
