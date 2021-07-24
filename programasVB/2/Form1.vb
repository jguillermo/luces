Public Class Form1
    Dim iii As Integer
    Dim jjj As Integer

    Dim datos(7, 5) As Integer
    Private Sub cambiarcolor(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click, Button2.Click, Button3.Click, Button4.Click, Button5.Click, Button6.Click, Button7.Click, Button8.Click, Button9.Click, Button10.Click, Button11.Click, Button12.Click, Button13.Click, Button14.Click, Button15.Click, Button16.Click, Button17.Click, Button18.Click, Button19.Click, Button20.Click, Button21.Click, Button22.Click, Button23.Click, Button24.Click, Button25.Click, Button26.Click, Button27.Click, Button28.Click, Button29.Click, Button30.Click, Button31.Click, Button32.Click, Button33.Click, Button34.Click, Button35.Click
        If sender.BackColor = Color.Red Then
            sender.BackColor = Color.Blue
        Else
            sender.BackColor = Color.Red
        End If
        generacodigo()
    End Sub
    Sub generacodigo()
        llenadatos()
        'Button
        Dim txtcol(5) As String
        Dim valdatos As Integer = 0
        For iii = 1 To 5
            For jjj = 7 To 1 Step -1
                valdatos = valdatos + 2 ^ (jjj - 1) * datos(8 - jjj, iii)
            Next
            txtcol(iii) = changebase(valdatos)
            valdatos = 0
        Next

        TextBox1.Text = "={" & txtcol(1) & "," & txtcol(2) & "," & txtcol(3) & "," & txtcol(4) & "," & txtcol(5) & "}"
    End Sub
    Function changebase(ByVal nudec As Integer) As String
        '<  >
        Dim nu2 As String
        Dim nu1 As String
        changebase = nudec.ToString
        If nudec > 15 Then
            nu1 = masde10(nudec \ 16)
            nu2 = masde10(nudec Mod 16)
        Else
            nu1 = "0"
            nu2 = masde10(nudec)
        End If
        changebase = "0x" & nu1 & nu2
    End Function
    Function masde10(ByVal nu As Integer) As String
        If nu > 9 Then
            Select Case nu
                Case 10 : masde10 = "A"
                Case 11 : masde10 = "B"
                Case 12 : masde10 = "C"
                Case 13 : masde10 = "D"
                Case 14 : masde10 = "E"
                Case 15 : masde10 = "F"
            End Select
        Else
            masde10 = nu.ToString
        End If

    End Function
    
    Sub llenadatos()
        datos(1, 1) = getdatos(Button1)
        datos(2, 1) = getdatos(Button2)
        datos(3, 1) = getdatos(Button3)
        datos(4, 1) = getdatos(Button4)
        datos(5, 1) = getdatos(Button5)
        datos(6, 1) = getdatos(Button6)
        datos(7, 1) = getdatos(Button7)

        datos(1, 2) = getdatos(Button8)
        datos(2, 2) = getdatos(Button9)
        datos(3, 2) = getdatos(Button10)
        datos(4, 2) = getdatos(Button11)
        datos(5, 2) = getdatos(Button12)
        datos(6, 2) = getdatos(Button13)
        datos(7, 2) = getdatos(Button14)


        datos(1, 3) = getdatos(Button15)
        datos(2, 3) = getdatos(Button16)
        datos(3, 3) = getdatos(Button17)
        datos(4, 3) = getdatos(Button18)
        datos(5, 3) = getdatos(Button19)
        datos(6, 3) = getdatos(Button20)
        datos(7, 3) = getdatos(Button21)


        datos(1, 4) = getdatos(Button22)
        datos(2, 4) = getdatos(Button23)
        datos(3, 4) = getdatos(Button24)
        datos(4, 4) = getdatos(Button25)
        datos(5, 4) = getdatos(Button26)
        datos(6, 4) = getdatos(Button27)
        datos(7, 4) = getdatos(Button28)


        datos(1, 5) = getdatos(Button29)
        datos(2, 5) = getdatos(Button30)
        datos(3, 5) = getdatos(Button31)
        datos(4, 5) = getdatos(Button32)
        datos(5, 5) = getdatos(Button33)
        datos(6, 5) = getdatos(Button34)
        datos(7, 5) = getdatos(Button35)
    End Sub
    Function getdatos(ByVal boton As Button) As Integer
        If boton.BackColor = Color.Red Then
            getdatos = 1
        Else
            getdatos = 0
        End If
    End Function

    
    Private Sub TextBox1_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TextBox1.TextChanged

    End Sub

    Private Sub Button36_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button36.Click
        Button1.BackColor = Color.Blue
        Button2.BackColor = Color.Blue
        Button3.BackColor = Color.Blue
        Button4.BackColor = Color.Blue
        Button5.BackColor = Color.Blue
        Button6.BackColor = Color.Blue
        Button7.BackColor = Color.Blue
        Button8.BackColor = Color.Blue
        Button9.BackColor = Color.Blue
        Button10.BackColor = Color.Blue
        Button11.BackColor = Color.Blue
        Button12.BackColor = Color.Blue
        Button13.BackColor = Color.Blue
        Button14.BackColor = Color.Blue
        Button15.BackColor = Color.Blue
        Button16.BackColor = Color.Blue
        Button17.BackColor = Color.Blue
        Button18.BackColor = Color.Blue
        Button19.BackColor = Color.Blue
        Button20.BackColor = Color.Blue
        Button21.BackColor = Color.Blue
        Button22.BackColor = Color.Blue
        Button23.BackColor = Color.Blue
        Button24.BackColor = Color.Blue
        Button25.BackColor = Color.Blue
        Button26.BackColor = Color.Blue
        Button27.BackColor = Color.Blue
        Button28.BackColor = Color.Blue
        Button29.BackColor = Color.Blue
        Button30.BackColor = Color.Blue
        Button31.BackColor = Color.Blue
        Button32.BackColor = Color.Blue
        Button33.BackColor = Color.Blue
        Button34.BackColor = Color.Blue
        Button35.BackColor = Color.Blue
        TextBox1.Text = ""
    End Sub
End Class
