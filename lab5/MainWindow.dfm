object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 472
  ClientWidth = 271
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 131
    Top = 59
    Width = 28
    Height = 14
    Caption = 'MAX'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 9
    Top = 60
    Width = 22
    Height = 13
    Caption = 'MIN'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object ButtonRandom: TButton
    Left = 61
    Top = 26
    Width = 145
    Height = 25
    Caption = 'Random'
    TabOrder = 0
    OnClick = ButtonRandomClick
  end
  object ButtonClose: TButton
    Left = 80
    Top = 435
    Width = 105
    Height = 25
    Caption = 'Close'
    TabOrder = 1
    OnClick = ButtonCloseClick
  end
  object EditMAX: TEdit
    Left = 165
    Top = 57
    Width = 68
    Height = 21
    TabOrder = 2
  end
  object EditMIN: TEdit
    Left = 37
    Top = 57
    Width = 69
    Height = 21
    TabOrder = 3
  end
  object ListBoxFirst: TListBox
    Left = 8
    Top = 84
    Width = 121
    Height = 345
    ItemHeight = 13
    TabOrder = 4
  end
  object ListBoxSecond: TListBox
    Left = 135
    Top = 84
    Width = 121
    Height = 345
    ItemHeight = 13
    TabOrder = 5
  end
end
