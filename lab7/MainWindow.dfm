object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 587
  ClientWidth = 476
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label3: TLabel
    Left = 48
    Top = 384
    Width = 114
    Height = 13
    Caption = 'Search or delete by key'
  end
  object Label4: TLabel
    Left = 37
    Top = 406
    Width = 18
    Height = 13
    Caption = 'Key'
  end
  object LabelGetALL: TLabel
    Left = 272
    Top = 21
    Width = 134
    Height = 13
    Caption = 'Information from hash table'
  end
  object Label1: TLabel
    Left = 54
    Top = 486
    Width = 92
    Height = 13
    Caption = 'First reached name'
  end
  object LabelName: TLabel
    Left = 30
    Top = 505
    Width = 141
    Height = 13
    Caption = '----------    ----------   ----------'
  end
  object Label2: TLabel
    Left = 36
    Top = 34
    Width = 137
    Height = 13
    Caption = 'Input information from array'
  end
  object MemoGetALL: TMemo
    Left = 216
    Top = 40
    Width = 241
    Height = 529
    Lines.Strings = (
      'MemoGetALL')
    TabOrder = 0
  end
  object EditKey: TEdit
    Left = 61
    Top = 403
    Width = 83
    Height = 21
    TabOrder = 1
  end
  object EditInfo: TEdit
    Left = 8
    Top = 313
    Width = 185
    Height = 21
    TabOrder = 2
  end
  object ButtonAddNewNode: TButton
    Left = 61
    Top = 340
    Width = 83
    Height = 25
    Caption = 'Add'
    TabOrder = 3
    OnClick = ButtonAddNewNodeClick
  end
  object ButtonSearchNode: TButton
    Left = 9
    Top = 443
    Width = 90
    Height = 25
    Caption = 'Search'
    TabOrder = 4
    OnClick = ButtonSearchNodeClick
  end
  object ButtonDeleteNode: TButton
    Left = 105
    Top = 443
    Width = 88
    Height = 25
    Caption = 'Delete'
    TabOrder = 5
    OnClick = ButtonDeleteNodeClick
  end
  object ButtonDeleteNegative: TButton
    Left = 97
    Top = 544
    Width = 96
    Height = 25
    Caption = 'Delete Negative'
    TabOrder = 6
    OnClick = ButtonDeleteNegativeClick
  end
  object ButtonClose: TButton
    Left = 16
    Top = 544
    Width = 75
    Height = 25
    Caption = 'Close'
    TabOrder = 7
    OnClick = ButtonCloseClick
  end
  object MemoKey: TMemo
    Left = 8
    Top = 53
    Width = 65
    Height = 197
    TabOrder = 8
  end
  object ButtonFromArray: TButton
    Left = 61
    Top = 264
    Width = 83
    Height = 25
    Caption = 'Add'
    TabOrder = 9
    OnClick = ButtonFromArrayClick
  end
  object MemoFIO: TMemo
    Left = 86
    Top = 53
    Width = 106
    Height = 197
    TabOrder = 10
  end
end
