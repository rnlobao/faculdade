//
//  Register2ViewController.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 22/09/22.
//

import UIKit

protocol ServiceDelegate {
    func dataSucess()
    func dataFail(error: Error)
    func showLoad()
    func removeLoad()
}

class Register2ViewController: UIViewController {

    @IBOutlet weak var registerButtonEdit: DefaultButton!
    @IBOutlet weak var emailTF: DefaultTextField!
    @IBOutlet weak var userTF: DefaultTextField!
    @IBOutlet weak var pwTF: DefaultTextField!
    @IBOutlet weak var confirmPWTF: DefaultTextField!
    @IBOutlet weak var alreadyHasAccountEdit: UIButton!
    
    @IBAction func AlreadyHasAccount(_ sender: Any) {
        let myViewController = LoginViewController()
        navigationController?.pushViewController(myViewController, animated: false)
    }
    
    private var viewModel: Register2ViewModel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        viewModel = Register2ViewModel(delegate: self)
        setupPWTextFields()
        setupToolBar()
        registerButtonEdit.isEnabled = true
        registerButtonEdit.configure(whatsInside: "Registrar")
        navigationHiddens()
    }
    
    private func navigationHiddens() {
        self.navigationController?.setNavigationBarHidden(true, animated: false)
        self.tabBarController?.tabBar.isHidden = true
    }
    
    override func viewDidAppear(_ animated: Bool) {
        if UserDefaults.standard.bool(forKey: "logado") {
            self.dismiss(animated: false)
        }
    }
    
    private func setupPWTextFields() {
        pwTF.isSecureTextEntry = true
        confirmPWTF.isSecureTextEntry = true
    }
    
    @IBAction func sendUser(_ sender: Any) {
        self.navigationController?.popToRootViewController(animated: true)

        //viewModel.postDataUser(login: userTF.text ?? "", email: emailTF.text ?? "", password: pwTF.text ?? "")
    }
    
    func setupToolBar() {
        setupToolBarPW()
        setupToolBarUser()
        setupToolBarEmail()
        setupToolBarConfirmPW()
    }
    
    private func setupToolBarEmail() {
        let keyboardToolbar = UIToolbar()
        keyboardToolbar.sizeToFit()
        let flexBarButton = UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil)
        
        let closeButtonItemEmail = UIBarButtonItem(title: "fechar", style: .done, target: self, action: #selector(closeKeyboardEmail))
        let nextButtonItemEmail = UIBarButtonItem(title: "próximo", style: .done, target: self, action: #selector(nextTextFieldEmail))
        keyboardToolbar.items = [flexBarButton, closeButtonItemEmail, nextButtonItemEmail]
        emailTF.inputAccessoryView = keyboardToolbar
    }
    
    private func setupToolBarUser() {
        let keyboardToolbar = UIToolbar()
        keyboardToolbar.sizeToFit()
        let flexBarButton = UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil)
        
        let closeButtonItemUser = UIBarButtonItem(title: "fechar", style: .done, target: self, action: #selector(closeKeyboardUser))
        let nextButtonItemUser = UIBarButtonItem(title: "próximo", style: .done, target: self, action: #selector(nextTextFieldUser))
        keyboardToolbar.items = [flexBarButton, closeButtonItemUser, nextButtonItemUser]
        userTF.inputAccessoryView = keyboardToolbar
    }
    
    private func setupToolBarPW() {
        let keyboardToolbar = UIToolbar()
        keyboardToolbar.sizeToFit()
        let flexBarButton = UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil)
        
        let closeButtonItemPW = UIBarButtonItem(title: "fechar", style: .done, target: self, action: #selector(closeKeyboardPW))
        let nextButtonItemPW = UIBarButtonItem(title: "próximo", style: .done, target: self, action: #selector(nextTextFieldPW))
        keyboardToolbar.items = [flexBarButton, closeButtonItemPW, nextButtonItemPW]
        pwTF.inputAccessoryView = keyboardToolbar
    }
    
    private func setupToolBarConfirmPW() {
        let keyboardToolbar = UIToolbar()
        keyboardToolbar.sizeToFit()
        let flexBarButton = UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil)
       
        
        let closeButtonItemconfirmPW = UIBarButtonItem(title: "fechar", style: .done, target: self, action: #selector(closeKeyboardConfirmPW))
        keyboardToolbar.items = [flexBarButton, closeButtonItemconfirmPW]
        confirmPWTF.inputAccessoryView = keyboardToolbar
    }
    
    
    @objc func closeKeyboardEmail() {
        emailTF.endEditing(true)
    }
    
    @objc func closeKeyboardUser() {
        userTF.endEditing(true)
    }
    
    @objc func closeKeyboardPW() {
        pwTF.endEditing(true)
    }
    
    @objc func closeKeyboardConfirmPW() {
        confirmPWTF.endEditing(true)
    }
    
    @objc func nextTextFieldEmail() {
        emailTF.resignFirstResponder()
        userTF.becomeFirstResponder()
    }
    
    @objc func nextTextFieldUser() {
        userTF.resignFirstResponder()
        pwTF.becomeFirstResponder()
    }
    
    @objc func nextTextFieldPW() {
        pwTF.resignFirstResponder()
        confirmPWTF.becomeFirstResponder()
    }
    
    
}

extension Register2ViewController: ServiceDelegate {
    func dataSucess() {
        let alert = UIAlertController(title: "Sucesso", message: nil, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "Continuar", style: .destructive, handler: {(action:UIAlertAction!) in
            self.navigationController?.popToRootViewController(animated: true)
        }))
        self.present(alert, animated: true)
        UserDefaults.standard.set(true, forKey: "logado")
        UserDefaults.standard.set(emailTF.text, forKey: "email")
        UserDefaults.standard.set(userTF.text, forKey: "usuario")
    }
        
    func dataFail(error: Error) {
        let alert = UIAlertController(title: "Erro", message: error.localizedDescription, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "Ok", style: .destructive, handler: nil))
        self.present(alert, animated: true)
    }
        
    func showLoad() {
        showSpinner(onView: view)
    }
        
    func removeLoad() {
        removeSpinner()
    }
}
