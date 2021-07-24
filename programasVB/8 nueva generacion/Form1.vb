Public Class Form1
    Dim iii As Integer
    Dim jjj As Integer
    Dim datos(7, 11) As Integer
    Dim txtcol(10) As String
    Dim txtcom As String
    Dim tamdeletra As Integer = 1
    Dim tipo As Integer = 1
    Dim valdatos As Integer = 0
    Sub tamletrafunction()

        For iii = 10 To 1 Step -1
            valdatos = 0
            For jjj = 7 To 1 Step -1
                valdatos = valdatos + datos(jjj, iii)
            Next
            If valdatos < 7 Then
                tamdeletra = iii
                Exit Sub
            End If
        Next
    End Sub
    Private Sub numuno(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click, Button2.Click, Button3.Click, Button4.Click, Button5.Click, Button6.Click, Button7.Click, Button8.Click, Button9.Click, Button10.Click, Button11.Click, Button12.Click, Button13.Click, Button14.Click, Button15.Click, Button16.Click, Button17.Click, Button18.Click, Button19.Click, Button20.Click, Button21.Click, Button22.Click, Button23.Click, Button24.Click, Button25.Click, Button26.Click, Button27.Click, Button28.Click, Button29.Click, Button30.Click, Button31.Click, Button32.Click, Button33.Click, Button34.Click, Button35.Click, Button36.Click, Button37.Click, Button38.Click, Button39.Click, Button40.Click, Button41.Click, Button42.Click, Button43.Click, Button44.Click, Button45.Click, Button46.Click, Button47.Click, Button48.Click, Button49.Click, Button50.Click, Button51.Click, Button52.Click, Button53.Click, Button54.Click, Button55.Click, Button56.Click, Button57.Click, Button58.Click, Button59.Click, Button60.Click, Button61.Click, Button62.Click, Button63.Click, Button64.Click, Button65.Click, Button66.Click, Button67.Click, Button68.Click, Button69.Click, Button70.Click
        If sender.BackColor = Color.Red Then
            sender.BackColor = Color.Blue
        Else
            sender.BackColor = Color.Red
        End If

        generacodigo()
    End Sub

    Sub generacodigo()
        llenadatos()
        TextBox3.Text = tamdeletra


        valdatos = 0
        For iii = 1 To tamdeletra
            For jjj = 1 To 7
                valdatos = valdatos + 2 ^ (jjj - 1) * datos(jjj, iii)
            Next
            txtcol(iii) = changebase(valdatos)
            valdatos = 0
        Next

        TextBox2.Text = "int const  [" & tamdeletra & "]={"
        For iii = 1 To tamdeletra - 1
            TextBox2.Text = TextBox2.Text & txtcol(iii) & ","
        Next
        TextBox2.Text = TextBox2.Text & txtcol(tamdeletra) & "};  //  "
        'int const A[5]={


        llenaclibor(TextBox2.Text)
        '{{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{1,1,1,1,1},{1,0,0,0,1},{1,0,0,0,1},{0,1,1,1,0}},  //  A
        '{1,0,0,0,1}
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

        datos(1, 6) = getdatos(Button36)
        datos(2, 6) = getdatos(Button37)
        datos(3, 6) = getdatos(Button38)
        datos(4, 6) = getdatos(Button39)
        datos(5, 6) = getdatos(Button40)
        datos(6, 6) = getdatos(Button41)
        datos(7, 6) = getdatos(Button42)


        datos(1, 7) = getdatos(Button43)
        datos(2, 7) = getdatos(Button44)
        datos(3, 7) = getdatos(Button45)
        datos(4, 7) = getdatos(Button46)
        datos(5, 7) = getdatos(Button47)
        datos(6, 7) = getdatos(Button48)
        datos(7, 7) = getdatos(Button49)


        datos(1, 8) = getdatos(Button50)
        datos(2, 8) = getdatos(Button51)
        datos(3, 8) = getdatos(Button52)
        datos(4, 8) = getdatos(Button53)
        datos(5, 8) = getdatos(Button54)
        datos(6, 8) = getdatos(Button55)
        datos(7, 8) = getdatos(Button56)


        datos(1, 9) = getdatos(Button57)
        datos(2, 9) = getdatos(Button58)
        datos(3, 9) = getdatos(Button59)
        datos(4, 9) = getdatos(Button60)
        datos(5, 9) = getdatos(Button60)
        datos(6, 9) = getdatos(Button62)
        datos(7, 9) = getdatos(Button63)



        datos(1, 10) = getdatos(Button64)
        datos(2, 10) = getdatos(Button65)
        datos(3, 10) = getdatos(Button66)
        datos(4, 10) = getdatos(Button67)
        datos(5, 10) = getdatos(Button68)
        datos(6, 10) = getdatos(Button69)
        datos(7, 10) = getdatos(Button70)

        tamletrafunction()
    End Sub
    Function getdatos(ByVal boton As Button) As Integer
        If boton.BackColor = Color.Red Then
            getdatos = 0
        Else
            getdatos = 1
        End If
    End Function
    Private Sub borra(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button36fdg.Click
        restboton()
    End Sub
    Sub restboton()
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
        Button36.BackColor = Color.Blue
        Button37.BackColor = Color.Blue
        Button38.BackColor = Color.Blue
        Button39.BackColor = Color.Blue
        Button40.BackColor = Color.Blue
        Button41.BackColor = Color.Blue
        Button42.BackColor = Color.Blue
        Button43.BackColor = Color.Blue
        Button44.BackColor = Color.Blue
        Button45.BackColor = Color.Blue
        Button46.BackColor = Color.Blue
        Button47.BackColor = Color.Blue
        Button48.BackColor = Color.Blue
        Button49.BackColor = Color.Blue
        Button50.BackColor = Color.Blue
        Button51.BackColor = Color.Blue
        Button52.BackColor = Color.Blue
        Button53.BackColor = Color.Blue
        Button54.BackColor = Color.Blue
        Button55.BackColor = Color.Blue
        Button56.BackColor = Color.Blue
        Button57.BackColor = Color.Blue
        Button58.BackColor = Color.Blue
        Button59.BackColor = Color.Blue
        Button60.BackColor = Color.Blue
        Button61.BackColor = Color.Blue
        Button62.BackColor = Color.Blue
        Button63.BackColor = Color.Blue
        Button64.BackColor = Color.Blue
        Button65.BackColor = Color.Blue
        Button66.BackColor = Color.Blue
        Button67.BackColor = Color.Blue
        Button68.BackColor = Color.Blue
        Button69.BackColor = Color.Blue
        Button70.BackColor = Color.Blue

        generacodigo()
    End Sub
    Sub llenaclibor(ByVal tex As String)
        My.Computer.Clipboard.Clear()
        My.Computer.Clipboard.SetText(tex)
    End Sub
    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        'For hu As Integer = 1 To 70
        '    TextBox3.Text = TextBox3.Text & "Button" & hu.ToString & ".Click, "
        'Next
        'Button1.Click, 
        generacodigo()
        'llenaclibor(TextBox3.Text)

    End Sub
    Private Sub cliktxt(ByVal sender As System.Object, ByVal e As System.EventArgs)
        llenaclibor(sender.text())
        sender.SelectAll()
    End Sub
    Private Sub CheckBox1_CheckedChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles CheckBox1.CheckedChanged
        If CheckBox1.Checked Then
            Me.TopMost = True
        Else
            Me.TopMost = False
        End If
    End Sub
    Private Sub Button71_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button71.Click
        'ABC
        Button71.BackColor = Color.Yellow
        Button72.BackColor = Color.LightGreen
        Button73.BackColor = Color.LightGreen
        Button74.BackColor = Color.LightGreen
        tipo = 1
    End Sub
    Private Sub Button72_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button72.Click
        'abc
        Button71.BackColor = Color.LightGreen
        Button72.BackColor = Color.Yellow
        Button73.BackColor = Color.LightGreen
        Button74.BackColor = Color.LightGreen
        tipo = 2
    End Sub
    Private Sub Button73_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button73.Click
        'numeros
        Button71.BackColor = Color.LightGreen
        Button72.BackColor = Color.LightGreen
        Button73.BackColor = Color.Yellow
        Button74.BackColor = Color.LightGreen
        tipo = 3
    End Sub
    Private Sub Button74_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button74.Click
        'simbolos
        Button71.BackColor = Color.LightGreen
        Button72.BackColor = Color.LightGreen
        Button73.BackColor = Color.LightGreen
        Button74.BackColor = Color.Yellow
        tipo = 4
    End Sub
End Class
