object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 107
  ClientWidth = 371
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
  object LabelTranslated: TLabel
    Left = 31
    Top = 44
    Width = 23
    Height = 16
    Caption = #1055#1060':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object LabelAnswer: TLabel
    Left = 14
    Top = 73
    Width = 40
    Height = 16
    Caption = #1054#1090#1074#1077#1090':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object LabelExercise: TLabel
    Left = 8
    Top = 17
    Width = 49
    Height = 16
    Caption = #1055#1088#1080#1084#1077#1088':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object EditForEx: TEdit
    Left = 63
    Top = 16
    Width = 169
    Height = 21
    TabOrder = 0
  end
  object EditTranslated: TEdit
    Left = 63
    Top = 43
    Width = 169
    Height = 21
    TabOrder = 1
  end
  object ButtonToSolve: TButton
    Left = 255
    Top = 14
    Width = 89
    Height = 25
    Caption = #1056#1072#1089#1089#1095#1080#1090#1072#1090#1100
    TabOrder = 2
    OnClick = ButtonToSolveClick
  end
  object ButtonClear: TButton
    Left = 255
    Top = 41
    Width = 89
    Height = 25
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100
    TabOrder = 3
    OnClick = ButtonClearClick
  end
  object EditAnswer: TEdit
    Left = 63
    Top = 70
    Width = 169
    Height = 21
    TabOrder = 4
  end
  object ButtonExit: TButton
    Left = 255
    Top = 68
    Width = 89
    Height = 25
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 5
    OnClick = ButtonExitClick
  end
end
