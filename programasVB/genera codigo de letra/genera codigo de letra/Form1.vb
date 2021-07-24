Public Class Form1
    Dim auxletra As String
    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        TextBox1.Text = TextBox1.Text.ToUpper
        auxletra = ""
        TextBox1.Text = TextBox1.Text.Trim & " "
        For i = 1 To TextBox1.TextLength
            buscaletra(Mid(TextBox1.Text, i, 1))
        Next
        auxletra = Mid(auxletra, 2)
        auxletra = "int frace[" & TextBox1.TextLength.ToString & "]={" & auxletra & "};"
        auxletra = auxletra & vbNewLine & "long nufra=" & TextBox1.TextLength
        auxletra = auxletra & ",tamletra=" & TextBox1.TextLength * 6 & ";"
        TextBox2.Text = auxletra
        My.Computer.Clipboard.Clear()
        My.Computer.Clipboard.SetText(auxletra)
    End Sub

    Sub buscaletra(ByVal letra As String)
        Dim lety As Integer = Asc(letra)
        If lety = 32 Then lety = 64
        If lety = 209 Then lety = 91
        auxletra = auxletra & "," & (lety - 64)
    End Sub

    Private Sub TextBox1_KeyUp(ByVal sender As Object, ByVal e As System.Windows.Forms.KeyEventArgs) Handles TextBox1.KeyUp
      
    End Sub   
End Class
