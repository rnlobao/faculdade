//
//  AddViewController.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 19/09/22.
//

import Foundation
import UIKit
import FirebaseFirestore
import FirebaseDatabase
import FirebaseAuth

struct Asets {
    let kind: Int
    let date: String
    let ticker: String
    let quantity: Int
    let price: Float
}

class AddViewController: UIViewController {
    
    @IBOutlet weak var registerButton: DefaultButton!
    @IBOutlet weak var pickerView: UIPickerView!
    @IBOutlet weak var tickerTF: DefaultTextField!
    @IBOutlet weak var qtdTF: DefaultTextField!
    @IBOutlet weak var priceTF: DefaultTextField!
    @IBOutlet weak var dateTF: DefaultTextField!
    
    
    var theActives: [String] = []
    
    let dataBase = Firestore.firestore()

    
    override func viewDidLoad() {
        setupPicker()
        theActives = ["Fii's", "Ações", "Criptoativos"]
        setupDateTF()
        registerButton.configure(whatsInside: "Adicionar")
    }
    
    private func writeData(active: Int, date: String, ticker: String, quantity: Int, price: Float) {
        
        let ref = Database.database().reference()
        let uid = Auth.auth().currentUser?.uid
        
        if active == 0 {
            ref.child("users").child(uid!).child("assets").child("fii").childByAutoId().setValue(["asset": active, "data": date, "ticker": ticker, "quantity": quantity, "price": price])
        } else if active == 1 {
            ref.child("users").child(uid!).child("assets").child("acoes").childByAutoId().setValue(["asset": active, "data": date, "ticker": ticker, "quantity": quantity, "price": price])
        } else if active == 2 {
            ref.child("users").child(uid!).child("assets").child("cripto").childByAutoId().setValue(["asset": active, "data": date, "ticker": ticker, "quantity": quantity, "price": price])
        }
        
        ref.observe(.childAdded) { data in
            let alert = UIAlertController(title: "Sucesso", message: nil, preferredStyle: .alert)
            alert.addAction(UIAlertAction(title: "Continuar", style: .destructive, handler: {(action:UIAlertAction!) in
                self.dateTF.text = ""
                self.tickerTF.text = ""
                self.priceTF.text = ""
                self.qtdTF.text = ""
            }))
            self.present(alert, animated: true)
        }
    }
    
    @IBAction func addButton(_ sender: Any) {
        let active: Int = pickerView.selectedRow(inComponent: 0)
        let date: String = self.dateTF.text ?? ""
        let ticker: String = self.tickerTF.text ?? ""
        let quantity: Int = Int(qtdTF.text ?? "") ?? 0
        let price: Float = Float(priceTF.text ?? "") ?? 0.0

        writeData(active: active, date: date, ticker: ticker, quantity: quantity, price: price)
    }
    
    func setupPicker() {
        pickerView.dataSource = self
        pickerView.delegate = self
    }
    
    private func setupQtdTf() {
        qtdTF.keyboardType = .numberPad
        priceTF.keyboardType = .decimalPad
    }
    
    private func setupDateTF() {
        dateTF.delegate = self
        dateTF.keyboardType = .numberPad
    }
    
    func setupToolBar() {
        setupToolBarTicker()
        setupToolBarQtd()
        setupToolBarPrice()
        setupToolBarDate()
    }
    
    private func setupToolBarTicker() {
        let keyboardToolbar = UIToolbar()
        keyboardToolbar.sizeToFit()
        let flexBarButton = UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil)
        
        let closeButtonItemEmail = UIBarButtonItem(title: "fechar", style: .done, target: self, action: #selector(closeKeyboardTicker))
        let nextButtonItemEmail = UIBarButtonItem(title: "próximo", style: .done, target: self, action: #selector(nextTextFieldTicker))
        keyboardToolbar.items = [flexBarButton, closeButtonItemEmail, nextButtonItemEmail]
        tickerTF.inputAccessoryView = keyboardToolbar
    }
    
    private func setupToolBarQtd() {
        let keyboardToolbar = UIToolbar()
        keyboardToolbar.sizeToFit()
        let flexBarButton = UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil)
        
        let closeButtonItemUser = UIBarButtonItem(title: "fechar", style: .done, target: self, action: #selector(closeKeyboardQtd))
        let nextButtonItemUser = UIBarButtonItem(title: "próximo", style: .done, target: self, action: #selector(nextTextFieldQtd))
        keyboardToolbar.items = [flexBarButton, closeButtonItemUser, nextButtonItemUser]
        qtdTF.inputAccessoryView = keyboardToolbar
    }
    
    private func setupToolBarPrice() {
        let keyboardToolbar = UIToolbar()
        keyboardToolbar.sizeToFit()
        let flexBarButton = UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil)
        
        let closeButtonItemPW = UIBarButtonItem(title: "fechar", style: .done, target: self, action: #selector(closeKeyboardPrice))
        let nextButtonItemPW = UIBarButtonItem(title: "próximo", style: .done, target: self, action: #selector(nextTextFieldPrice))
        keyboardToolbar.items = [flexBarButton, closeButtonItemPW, nextButtonItemPW]
        priceTF.inputAccessoryView = keyboardToolbar
    }
    
    private func setupToolBarDate() {
        let keyboardToolbar = UIToolbar()
        keyboardToolbar.sizeToFit()
        let flexBarButton = UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil)
        
        let closeButtonItemconfirmPW = UIBarButtonItem(title: "fechar", style: .done, target: self, action: #selector(closeKeyboardDate))
        keyboardToolbar.items = [flexBarButton, closeButtonItemconfirmPW]
        dateTF.inputAccessoryView = keyboardToolbar
    }
    
    @objc func closeKeyboardTicker() {
        tickerTF.endEditing(true)
    }
    
    @objc func closeKeyboardQtd() {
        qtdTF.endEditing(true)
    }
    
    @objc func closeKeyboardPrice() {
        priceTF.endEditing(true)
    }
    
    @objc func closeKeyboardDate() {
        dateTF.endEditing(true)
    }
    
    @objc func nextTextFieldTicker() {
        tickerTF.resignFirstResponder()
        qtdTF.becomeFirstResponder()
    }
    
    @objc func nextTextFieldQtd() {
        qtdTF.resignFirstResponder()
        priceTF.becomeFirstResponder()
    }
    
    @objc func nextTextFieldPrice() {
        priceTF.resignFirstResponder()
        dateTF.becomeFirstResponder()
    }
}

extension AddViewController: UIPickerViewDelegate, UIPickerViewDataSource {
    func numberOfComponents(in pickerView: UIPickerView) -> Int {
        return 1
    }
    
    func pickerView(_ pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        return theActives.count
    }
    
    func pickerView(_ pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String? {
        return theActives[row]
    }
}

extension AddViewController: UITextFieldDelegate {
    func textField(_ textField: UITextField, shouldChangeCharactersIn range: NSRange, replacementString string: String) -> Bool {
        if textField == dateTF {
            if (dateTF?.text?.count == 2) || (dateTF?.text?.count == 5) {
                if !(string == "") {
                    dateTF?.text = (dateTF?.text)! + "/"
                }
            }
            return !(textField.text!.count > 9 && (string.count ) > range.length)
        }
        else {
            return true
        }
    }
}
