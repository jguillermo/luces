Public Class Form1


   

 
    Private Sub cambiarcolor(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click, Button2.Click, Button3.Click, Button4.Click, Button5.Click, Button6.Click, Button7.Click, Button8.Click, Button9.Click, Button10.Click, Button11.Click, Button12.Click, Button13.Click, Button14.Click, Button15.Click, Button16.Click, Button17.Click, Button18.Click, Button19.Click, Button20.Click, Button21.Click, Button22.Click, Button23.Click, Button24.Click, Button25.Click, Button26.Click, Button27.Click, Button28.Click, Button29.Click, Button30.Click, Button31.Click, Button32.Click, Button33.Click, Button34.Click, Button35.Click
        If sender.BackColor = Color.Red Then
            sender.BackColor = Color.Blue
        Else
            sender.BackColor = Color.Red
        End If
        txtchange()
    End Sub
    Sub txtchange()
        MsgBox("inicio")
    End Sub
   
End Class
